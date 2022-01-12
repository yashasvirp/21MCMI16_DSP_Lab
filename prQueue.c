//Priority queue has been implemented. Highest marks have been considered as highest priority elements.

#include<stdio.h>
#include<string.h>
#define SIZE 10					//queue size
#define SMAX 25					//string size
typedef struct prqueue{
	int m;
	char name[SMAX];
};

struct prqueue ar[SIZE];
int f=0,r=-1;

void insert(char n[], int m){
	
	strcpy(ar[++r].name,n);
	ar[r].m = m;
}

//With multiple hih priority elements, for deletion, first element with highest priority in the queue will be deleted

struct prqueue delete(){
	int pos = 0, i = f;
	struct prqueue ele;
	
											//get highest priority elements
	
	for(i = f; i <= r; i++){
		if(ar[i].m > ar[pos].m)
	 		pos = i;
	 }
	 
	strcpy(ele.name, ar[pos].name);
	ele.m = ar[pos].m;
	
											//shifting all elements from front to rear(left to right) in the queue
	for(i=pos;i>f;i--){
		strcpy(ar[i].name,ar[i-1].name);
		ar[i].m = ar[i-1].m;
	}
	
	f++;									//increment front
	
	printf("\nDeleted elements are:");	
	return ele;
}

void Display(){
	int i;
	
	for(i=f;i<=r;i++)
		printf("\n%s\t%d",ar[i].name, ar[i].m);
}

void Displayele(struct prqueue ele){				//FOR DISPLAYING A PARTICULAR ELEMENT 

		printf("\n%s\t%d",ele.name, ele.m);
}

void getPriority(){									//getting highest priority elements
	
	struct prqueue ele;
	int i,pos = 0;
	
	if(f>r){
		printf("\nNo elements in the queue");
	}
	
	//get position of highest priority element
	for(i = f; i <= r; i++){
		if(ar[i].m > ar[pos].m)
	 		pos = i;
	 }
	 
	//print all highest priority elements
	 
	for(i=f;i<=r; i++){
		if(ar[i].m == ar[pos].m)
			printf("\n%s\t%d",ar[i].name, ar[i].m);
	}
}

void main(){
	
	int ch,x,m;
	char n[SIZE];
	DisplayMenu();

	do{
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1){
			
			if(r == SIZE-1){
			printf("\nOverflow! Cannot insert data!");
			continue;	
			}
			printf("\nEnter name: ");
			scanf("%s",n);
			printf("\nEnter marks: ");
			scanf("%d",&m);
			insert(n,m);
		}
		else if(ch == 2){
			if(f>r){
				printf("\nUnderflow! Cannot delete element!");
			}
			else
			Displayele(delete());
		}
		else if(ch == 3){
				Display();
		}
		else if(ch ==4)
				getPriority();
		else if(ch == 5)
				DisplayMenu();
		else if(ch == 6)
				break;				
		else
			printf("\nEnter a valid choice!");	
		
	}while(ch != 6);
}

void DisplayMenu(){
	
	printf("\nOperations Menu:");
	printf("\n1.Insert\n2. Delete\n3. Display\n4. Get prioritised elements\n5. Display\n6. Exit");
}
	
