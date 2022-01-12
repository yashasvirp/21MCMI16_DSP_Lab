#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000


int partition(int ar[], int l, int h){
	int i = l, j = h, temp, pivot = h;
	
	while(i < j){
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
	
	int lim = h-l+1;
	int median, m1 = l + (1/4)*lim, m2 = l + lim/2, m3 = l + (3/4)*lim;
	
	if(a[m1] >= a[m3] && a[m1] < a[m2])
		median = m1;
	else if(a[m3] >= a[m1] && a[m3] < a[m2])
		median = m3;
	else
		median = m2;
	
	return median;
}
	
void medianqsort(int ar[], int l, int h){
	int p,m,temp;
	
	if(l < h){
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
	
	FILE *fp = fopen("Rand105.txt","r");
	
	
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
	
	Ttime = ((double)(end - begin))/CLOCKS_PER_SEC;
	
	printf("\nTime taken is %lf sec\n",Ttime);
}


