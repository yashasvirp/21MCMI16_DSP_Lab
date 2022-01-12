#include<stdio.h>
typedef struct node{
	int data;
	struct node* next;
};

struct node *top = NULL;

void main(){
	int x, ch;
	printf("\nStack operations:\n1. Push \n2. Pop\n3. Display\n4. Exit");
	do{
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		
		if(ch == 1){
			printf("\nEnter element:");
			scanf("%d", &x);
			Push(x);
		}
		
		else if(ch == 2){
			pop();		
		}
		else if(ch == 3)
				Display();

		else if(ch == 4);
		else
			printf("\nEnter a valid choice!");
		
	}while(ch != 4);
	printf("\nOperations complete!");
}

void Push(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data; temp->next = NULL;
	
	if(top == NULL){
		top = temp;
	}
	else{
		temp->next = top;
		top = temp;
	}
	printf("\nNode with data as %d pushed successfully", data);
	Display();
}

void pop(){
	struct node *temp = top;
	if(top == NULL){
		printf("\nUnderflow. Stack empty!");
		return;
	}
	top = top->next;
	printf("\nElement %d popped successfully.",temp->data);
	free(temp);
}
void Display(){
	
	struct node *temp = top;
	
	if(top == NULL)
		{
			printf("\nEmpty Stack");
			return;
		}
	
	printf("\n[Top] ");
	
	while(temp!=NULL){
		printf("%d<-",temp->data);
		temp = temp->next;
	}
}
