#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000000
void main(){
	
	int i;
	int *ar = (int*)malloc(sizeof(int)*SIZE);
	int lim = SIZE*0.01,temp,count = 0;
	
	
	FILE *fp = fopen("Sort106.txt","w");
	
	//create array of random numbers
	for(i = 0; i < SIZE; i++)
		ar[i] = i%100;
	
	
	/*
	//swap 1% of pairs to almost sort them
	
	for(i = 0; i < SIZE-1; i++){
		if(ar[i] < ar[i+1]){
			temp = ar[i];
			ar[i] = ar[i+1];
			ar[i+1] = temp;
			count++;
		}
		
		if(count == lim)
			break;
	}
	
	*/
	
	//transfer input to file
	for(i = 0; i < SIZE; i++)
		fprintf(fp,"%d",ar[i]);
			
	
	fclose(fp);
}
