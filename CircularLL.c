#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 25
#define NUMBER_OF_STRINGS 3
#define NUMBER_OF_NODES 5
typedef struct node{
	char *info[NUMBER_OF_STRINGS];
	struct node *link;
};

struct node *head = NULL, *rear = NULL;



struct node* createNode(){
	
	int i;
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	
	for(i = 0; i < NUMBER_OF_STRINGS; i++)
		temp->info[i] = (char*)malloc(SIZE*sizeof(char));
	
	temp->link = NULL;
	return temp;
}

void insertNode(char *ar[]){
	
	struct node *temp = createNode();
	int i;
	
	for(i = 0; i < NUMBER_OF_STRINGS; i++)
			strcpy(temp->info[i],&ar[i]);
	
	if(head == NULL){
		head = temp;
		rear = temp;	
	}
	else{
		rear->link = temp;
		rear = temp;
		rear->link = head;
	}
	
}

void Display(){
	int i,count = 0;
	struct node *temp = head;
	if(head == NULL)
		printf("\n Empty List");
	
	while(count < NUMBER_OF_NODES){
			printf("\n");
			for(i = 0; i < NUMBER_OF_STRINGS; i++)
				printf("%s\t ",temp->info[i]);
			temp = temp->link;	
			count++;		
	}
}

void DisplaySecond(){
	
	int count = 0;
	struct node *temp = head;
	
	if(head == NULL)
		printf("\n Empty List");
	
	printf("\n\nSecond Strings:");
	
	while(count < NUMBER_OF_NODES){
			printf("\n");
			printf("%s\t ",temp->info[1]);
			temp = temp->link;
			count++;		
	}
}

void checkNodes(){
	
	struct node *temp = head;
	int flag = 0, count = 0;
	
	while(count < NUMBER_OF_NODES){
		
		if(strcmp(temp->info[NUMBER_OF_STRINGS-1] , temp->link->info[0]) != 0)
			flag = 1;
			
		temp = temp->link;
		count++;
	}
	
	if(flag == 1)
		printf("\n\nStrings do not match!");
	else
		printf("\n\nValid Strings!");
		
}

void changeVal(struct node *temp){
	
	char ar[SIZE];
	
	printf("\n\nEnter changing value for first string: ");
	scanf("%s",ar);
	
	strcpy(temp->info[0],ar);
	
}

void main(){
	
	char *ar[NUMBER_OF_STRINGS];
	int i = 0, j;
	
	while(i < NUMBER_OF_NODES){
		
		printf("\nEnter strings for node %d: ",i+1);
		for(j = 0; j < NUMBER_OF_STRINGS; j++)
			scanf("%s",&ar[j]);
	
		insertNode(ar);
		i++;
	}
	
	Display();
	
	DisplaySecond();
	
	checkNodes();
	
	struct node *temp = head;
	
	printf("\n\nFor first node: ");
	changeVal(temp);
	
	printf("\n\nFor last node: ");
	
	while(temp->link != head)
		temp = temp->link;
		
	changeVal(temp);
	
	Display();
	
	checkNodes();
}
