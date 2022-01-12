#include<stdio.h>
#define SIZE 16 //Array size
#define Q1 5
#define Q2 3
#define Q3 2
#define Q4 6
#define k 4
int ar[SIZE];
//q1[Q1],q2[Q2],q3[Q3],q4[Q4];
int f[k],r[k],count[k];

void main(){
	int i;
	
	initArray(ar);
}

void initArray(int ar[]){
	int i = 0;
	for(i = 0; i < k; i++){
		f[i] = -1;
		r[i] = -1;
		count[i] = 0;
	}
}

int countEle(int q[]){
	int i = 0;
	
}

void insert(int x){
	
}
void insertq(int i, int x){
		int qno = i-1;
		
		//inserting first element in the queue
		if(f[qno] == -1 && r[qno] == -1){
			if(f[qno+1] != -1){
				
			}
			ar[++r[qno]] = x;
			f[qno] = r[qno];
		}
		else{
			
		}
			
		count[qno]++;
		//arrangeArr();
}


/*
void arrangeArr(){
	int i = 0,j = 0;
	while(i < SIZE-1 && j < Q1){
		ar[i++]= q1[i++];
	}
	j = 0;
	while(i < SIZE-1 && j < Q2){
		ar[i++]= q2[j++];
	}
	j = 0;
	while(i < SIZE-1 && j < Q3){
		ar[i++]= q3[j++];
	}
	while(i < SIZE-1 && j < Q4){
		ar[i++]= q4[j++];
	}	
}

*/
