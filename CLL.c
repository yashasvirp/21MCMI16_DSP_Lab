#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;

struct node *splitLL(struct node *head){
	
	int count = 0;
	struct node *head2, *temp = head;
	int j, i;
	
	if(temp == NULL){
		printf("\nEmpty List, cannot be split!");
		return;
	}
	else{
		do{
			count++;
			temp = temp->next;
		}while(temp != head);
	}
	
	j = count/2;
	//Dividing number of nodes into 2 parts
	if(count%2 == 0)
		i = j;
	else 
		i = j+1;
	

	//splitting the list for first list and making it circular 
	while(--i){
		temp = temp->next;
	}
	head2 = temp->next;
	temp->next = head;
	
	//making second list circular
	
	
	printf("\nFirst list:\n");
	Display(head);
	
	if(j == 0){
		printf("\n\nNo second list further!");
		return;
	}
	
	temp = head2;
	
	while(--j){
		temp = temp->next;		
	}
	temp->next = head2;
	
	printf("\n\nSecond list:\n");
	Display(head2);
	
	return head2;
	
}

void Display(struct node *head){
		
	struct node *temp = head;
	
	if(head == NULL){
		printf("\nEmpty List!");
		return;
	}
	else{
		
		printf("\n[HEAD] ");
		do{
			printf("%d->",temp->data);
			temp = temp->next;
		}while(temp != head);
		printf("[%d ",temp->data);
		printf("HEAD]");
	}
}


struct node *createNode(int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

struct node *InsertAtBeg(struct node *head, int data){
	
	struct node *temp, *curr = head;
	
	temp = createNode(data);
	
	if(head == NULL){
		head = temp;
		temp->next = head;
	}
	else{
		do{
			curr = curr->next;
		}while(curr->next != head);
		
		temp->next = head;
		curr->next = temp;
		head = temp;
	}
	
	return head;

}

struct node *InsertAtEnd(struct node *head, int data){
	
	struct node *temp, *curr = head;
	
	temp = createNode(data);
	
	if(head == NULL){
		head = temp;
		temp->next = head;
	}
	else{
		do{
			curr = curr->next;
		}while(curr->next != head);
		
		temp->next = head;
		curr->next = temp;
	}
	
	return head;

}

void main(){
	
	int ch,x;
	struct node *head2 = NULL;
	DisplayMenu();

	do{
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1){
			printf("\nEnter element:");
			scanf("%d", &x);
			head = InsertAtBeg(head, x);
			Display(head);
		}
		else if(ch == 2){
			printf("\nEnter element:");
			scanf("%d", &x);
			head = InsertAtEnd(head, x);
			Display(head);
		}
		else if(ch == 3){
				printf("\nSplitting first list!");
				head2 = splitLL(head);
		}
		else if(ch == 4){
				printf("\nSplitting second list!");
					head2 = splitLL(head2);
		} 
		else if(ch ==5)
				DisplayMenu();
		else if(ch == 6)
				break;				
		else
			printf("\nEnter a valid choice!");	
		
	}while(ch != 6);
}

void DisplayMenu(){
	printf("\nOperations Menu:");
	printf("\n1. Insert at Beginning\n2. Insert at end\n3. Split first list\n4. Split second list\n5. Display menu\n6. Exit");
}
