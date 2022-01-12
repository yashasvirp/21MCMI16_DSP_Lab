#include<stdio.h>
#include<limits.h>
#define SIZE 20

int max(int ar[], int n){
	
	int max, i;
	
	for(i = 0; i < n; i++)
		if(ar[i] > max)
			max = ar[i];
	
	return max;
}
void countSort(int ar[], int n, int pos){
	
	int range[10],i,j,p;		//size of range array is fixed 
	int op[n],val;
	
	for(i = 0; i <= 10; i++)
		range[i] = 0;
	
	for(j = 0; j < n; j++){
		p = (ar[j]/pos)%10;
		++range[p];
	}
	
	for(i = 1; i <= 10; i++)
		range[i] += range[i-1];
	
	for(i = n-1; i >= 0; i--){
		p = (ar[i]/pos)%10;
		val = --range[p];
		op[val]=ar[i];
	}
		
	for(i = 0; i < n; i++)
		ar[i] = op[i];
}

void radixSort(int ar[], int n){
	
	int m = max(ar,n);
	
	int pos,i;
	
	for(pos = 1; m/pos > 0; pos *= 10)
		countSort(ar,n,pos);
	
	for(i = 0; i < n; i++)
		printf("%d ",ar[i]);
}

void main(){
	
	int i,ar[SIZE],n, max = INT_MIN,exp;
	
	printf("\nEnter range of ele: ");
					scanf("%d",&n);
	
	printf("\nEnter elements: ");
	for(i = 0; i < n; i++){
			scanf("%d",&ar[i]);
		
		if(ar[i] > max)
			max = ar[i];
	}
	
    radixSort(ar, n);
}


