#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 1000000


int partition(int ar[], int l, int h){
	int i = l, j = h, temp, pivot = h;
	
	while(i <= j){
		while(ar[i] <= ar[pivot])
			i++;
		while(ar[j] > ar[pivot])
			j--;
		if(i < j){
			temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}
	}
	
	temp = ar[j];
	ar[j] = ar[pivot];
	ar[pivot] = temp;

	return j;
}

int median(int a[],int l, int h){
	
	int median, m = (l+h)/2;
	
	if(a[l] >= a[h] && a[l] < a[m])
		median = l;
	else if(a[h] >= a[l] && a[h] < a[m])
		median = h;
	else
		median = m;
	
	return median;
}
	
void medianqsort(int ar[], int l, int h){
	int p,m,temp;
	
	if(l <= h){
		m = median(ar,l,h);
		temp = ar[m];
		ar[m] = ar[h];
		ar[h] = temp;
		p = partition(ar,l,h);
		medianqsort(ar,l,p-1);
		medianqsort(ar,p+1,h);
	}
}
	

void main(){
	int i, l=0, h=SIZE;
	int *ar = (int*)malloc(sizeof(int)*SIZE);
	double Ttime;
	clock_t begin,end;
	
	FILE *fp = fopen("Rand106.txt","r");
	
	
	for(i=0;i<SIZE;i++)
		fscanf(fp,"%d",&ar[i]);
	
	fclose(fp);
	
	/*
	printf("\nThe array is:\n");
	for(i=0;i<SIZE;i++)
		printf("%d ", ar[i]);
		
	*/
	
	begin = clock();
	
	medianqsort(ar,l,h-1);
	
	end = clock();
	
	/*	
	printf("\nThe sorted array is:\n");
	for(i=0;i<SIZE;i++)
		printf("%d ", ar[i]);
	
	*/
	
	Ttime = ((double)(end-begin))/CLOCKS_PER_SEC;
	
	printf("\nTime taken is %lf sec\n",Ttime);
}


