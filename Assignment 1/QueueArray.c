#include<stdio.h>
#include<stdbool.h>
#define SIZE 10
int ar[SIZE], f = 0, r = -1;

bool dequeue(void);
//void enqueue(int);
//void display(void);

void main(){
	int ch, x, ele;
	
	printf("\nQueue operations:\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit");
	
	do{
		printf("\nEnter your Choice: ");
		scanf("%d", &ch);
		
		if(ch ==1){
				enqueue(x);
		}
		else if(ch ==2){
				ele = ar[f];
				if(dequeue() == false)
					printf("\nunsuccessful operation!");
				else
					printf("\ndeleted element is: %d",ele);
		}
		
		else if(ch == 3)
				display();	
		else if(ch == 4);
		else
		 printf("\nEnter a valid choice");
	}while(ch!=4);
	
	printf("\nOperations complete!");
		
}

void enqueue(int x){
	if(r == SIZE-1)
		printf("\nOverflow! No enqueue allowed");
	else{
		printf("\nEnter element: ");
		scanf("%d", &x);
		ar[++r] = x;
	}
		
}

bool dequeue(){
	if(f == (r+1))
		{
			printf("\nUnderflow!"); 
			return false;
		}
	else
	f++;
	return true;
}

void display(){
	int i;
	if(f == r+1){
		printf("\nQueue empty!");
		return;
	}
	printf("\ncontents of the queue are:\n");
	for(i = f; i <=r; i++)
		printf("%d ",ar[i]);
}
