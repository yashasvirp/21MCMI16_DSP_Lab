#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 1000000


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


void qsort1(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int *stack = (int*)malloc(sizeof(int)*(h - l + 1));
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    
    free(stack);
}

void main(){
	int i, l=0, h=SIZE;
	int *ar = (int*)malloc(sizeof(int)*SIZE);
	clock_t begin,end;
	double Ttime;
	
	FILE *fp = fopen("Rand107.txt","r");
	
	
	for(i=0;i<SIZE;i++)
		fscanf(fp,"%d",&ar[i]);
	
	fclose(fp);
	
/*
	printf("\nThe array is:\n");
	for(i=0;i<SIZE;i++)
		printf("%d ", ar[i]);
*/
		
	begin = clock();
	
	qsort1(ar,l,h-1);
	
	end = clock();
		
/*
	printf("\nThe sorted array is:\n");
	for(i=0;i<SIZE;i++)
		printf("%d ", ar[i]);
*/
	free(ar);
	Ttime = ((double)(end - begin))/CLOCKS_PER_SEC;
	
	printf("\nTime taken is %lf sec\n",Ttime);
}
