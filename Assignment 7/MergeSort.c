#include <stdio.h>  
#include<stdlib.h>
#include<time.h>
#define SIZE 10000000
/* Function to merge the subarrays of a[] */  
void merge(int a[], int l, int mid, int r)    
{    
    int i, j, k;  
    int m = mid - l + 1;    
    int n = r - mid;    
      
    int *Left = (int*)malloc(sizeof(int)*m);
	int *Right = (int*)malloc(sizeof(int)*n);; //temporary arrays  
      
    for (i = 0; i < m; i++)    
	Left[i] = a[l + i];    
    for ( j = 0; j < n; j++)    
	Right[j] = a[mid + 1 + j];    
      
    i = 0; 
    j = 0;    
    k = l;  
      
    while (i < m && j < n)    
    {    
        if(Left[i] <= Right[j])
            a[k++] = Left[i++];    
        else    
            a[k++] = Right[j++];
    }    
    while (i<m)    
    {    
        a[k++] = Left[i++];       
    }    
      
    while (j<n)    
    {    
        a[k++] = Right[j++];  
    }    
}    
  
void mergeSort(int a[], int l, int r)  
{  
    if (l < r)   
    {  
        int mid = (l + r) / 2;  
        mergeSort(a, l, mid);  
        mergeSort(a, mid + 1, r);  
        merge(a, l, mid, r);  
    }  
}  
  
/* Function to print the array */  
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
  
int main()  
{  
    int i, l=0, h=SIZE;
	int *ar = (int*)malloc(sizeof(int)*SIZE);
	clock_t begin,end;
	double Ttime;
	

	FILE *fp = fopen("AlmSort107.txt","r");
	
	
	for(i=0;i<SIZE;i++)
		fscanf(fp,"%d",&ar[i]);
	
	fclose(fp);
	
	/*
	printf("\nThe array is:\n");
	for(i=0;i<SIZE;i++){
		ar[i] = rand()%SIZE;
		printf("%d ", ar[i]);
	}
	
	*/	
	begin = clock();
	
	mergeSort(ar,l,h-1);
	
	end = clock();
		
	/*
	printf("\nThe sorted array is:\n");
	for(i=0;i<SIZE;i++)
		printf("%d ", ar[i]);
	
	*/
	free(ar);
	Ttime = ((double)(end - begin))/CLOCKS_PER_SEC;
	
	printf("\nTime taken is %lf sec\n",Ttime);
    return 0;  
}  
