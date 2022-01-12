#include<stdio.h>
struct node{
	int data;
	struct node* next;
};

struct node *f = NULL, *r = NULL;

void main(){
	int x, ch;
	printf("\nQueue operations:\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit");
	do{
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		
		if(ch == 1){
			printf("\nEnter element:");
			scanf("%d", &x);
			enqueue(x);
		}
		
		else if(ch == 2){
			dequeue();		
		}
		else if(ch == 3)
				Display();

		else if(ch == 4);
		else
			printf("\nEnter a valid choice!");
		
	}while(ch != 4);
	printf("\nOperations complete!");
}

void enqueue(int data){
	struct node *temp = (struct node*)malloc(sizeof(node));
	temp->data = data; temp->next = NULL;
	
	if(r == NULL && f ==NULL){
		f = temp; r = temp;
	}
	else{
		r->next = temp;
		r = temp;
		r->next = NULL;
	}
	printf("\nNode with data as %d queued successfully", data);
	Display();
}

void dequeue(){
	struct node *temp = f;
	if(f == NULL ){
		printf("\nUnderflow. Queue empty!");
		return;
	}
	f = f->next;
	printf("\nElement %d removed successfully.",temp->data);
	free(temp);
}
void Display(){
	
	struct node *temp = f;
	
	if(f == NULL)
		{
			printf("\nEmpty Queue");
			return;
		}
	
	printf("\n[FRONT] ");
	
	while(temp!=NULL){
		printf("%d<-",temp->data);
		temp = temp->next;
	}
	printf("[REAR]");
}
