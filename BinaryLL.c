#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node *head = NULL;
void insertAtBig(int data);
void Display();


void insertAtBeg(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data; temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
	Display();
	return;
}

void Display(){
	
	struct node *temp = head;
	
	if(head == NULL)
		{
			printf("\nEmpty list");
			return;
		}
	
	printf("\n[HEAD] ");
	
	while(temp!=NULL){
		printf("->%d",temp->data);
		temp = temp->next;
	}
	printf("[NULL]");
	return;
}

void main(){
	int x, cnt = 0,sum = 0;
	char ch;
	printf("\nEnter a digit and press Enter. To terminate and get result, press 2");
	printf("\nNOTE - Digits will be inserted at the beginning of the list");
	do{
		printf("\nEnter the digit: ");
		scanf("%d",&x);
		if(x == 0 || x == 1){
			insertAtBeg(x);
			sum += x*pow(2,cnt); 
			cnt++;
		}
		else if(x == 2)			//exit condition
				break;
		else
			printf("\nEnter only 0 or 1!");
		
	}while(x != 2);
	
	
	printf("\nThe sum is %d",sum);
}

