#include<stdio.h>
#include<stdbool.h>
#define SIZE 10
int ar[SIZE], top = -1;

bool pop(void);

void main(){
	int ch, x, ele;
	
	printf("\nStack operations:\n1. Push \n2. Pop\n3. Display\n4. Exit");
	
	do{
		printf("\nEnter your Choice: ");
		scanf("%d", &ch);
		
		if(ch ==1){
			printf("\nEnter element: ");
				scanf("%d", &x);
				push(x);
		}
		else if(ch ==2){
				ele = ar[top];
				if(pop() == false)
					printf("\nunsuccessful operation!");
				else
					printf("\nPopped element is: %d",ele);
		}
		
		else if(ch == 3)
				display();	
		else if(ch == 4);
		else
		 printf("\nEnter a valid choice");
	}while(ch!=4);
	
	printf("\nOperations complete!");
		
}

void push(int x){
	if(top == SIZE-1)
		printf("\nOverflow! No push allowed");
	else
		ar[++top] = x;
}

bool pop(){
	if(top == -1)
		{
			printf("\nUnderflow!"); 
			return false;
		}
	else
	ar[top--];
	return true;
}

void display(){
	int i;
	if(top == -1){
		printf("\nStack empty!");
		return;
	}
	printf("\ncontents of the stack are:\n");
	for(i = top; i >=0; i--)
		printf("%d\n",ar[i]);
}
