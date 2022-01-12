#include<stdio.h>
#define SIZE 100
int count = -1; 		//count does not provide number of elements, count+1 does

void display(int ar[], int n){
	int i;
	
	if(n == -1){
		printf("\nNo elements present in the heap yet!");
		return;
	}
	
	printf("\n");
	for(i = 0; i <= n; i++)
		printf("%d ",ar[i]);
}


void maxHeapify(int ar[], int hsize, int i){
	
	int l = 2*i+1, r = 2*i+2;
	int temp, max = i;
	
	if(l < hsize && ar[l] > ar[i])
		max = l;
	
	if(r < hsize && ar[r] > ar[max])
		max = r;
	
	if(max != i){
		temp = ar[i];
		ar[i] = ar[max];
		ar[max] = temp;
		maxHeapify(ar,hsize,max);
	}
}


void buildMaxHeap(int ar[], int n){
	int i;
	for(i = n/2; i >=0; i--)
		maxHeapify(ar,n,i);
}


void minHeapify(int ar[], int hsize, int i){
	
	int l = 2*i+1, r = 2*i+2;
	int temp, min = i;
	
	if(l < hsize && ar[l] < ar[i])
		min = l;
	
	if(r < hsize && ar[r] < ar[min])
		min = r;
	
	if(min != i){
		temp = ar[i];
		ar[i] = ar[min];
		ar[min] = temp;
		minHeapify(ar,hsize,min);
	}
}


void buildMinHeap(int ar[], int n){
	int i;
	for(i = n/2; i >=0; i--)
		minHeapify(ar,n,i);
}

//For heapsort, we use traditional method which requires max-heap
//for that, we first convert the current array into max-heap and then sort it.

void heapSortMax(int ar[]){
	int hsize = count+1;
	int i,temp;
	
	if(count == -1){
		printf("\nNo elements present in the heap yet!");
		return;
	}
	
	buildMaxHeap(ar,count+1);
	
	for(i = count; i >= 0; i--){
		temp = ar[i];
		ar[i] = ar[0];
		ar[0] = temp;
		hsize--;
		maxHeapify(ar,hsize,0);
	}
	
	display(ar,count);
}


//using Min Heap, sorting will be done in descending order.
void heapSortMin(int ar[]){
	
	int hsize = count+1;
	int i,temp;
	
	if(count == -1){
		printf("\nNo elements present in the heap yet!");
		return;
	}
	
	buildMinHeap(ar,count+1);
	
	for(i = count; i >= 0; i--){
		temp = ar[i];
		ar[i] = ar[0];
		ar[0] = temp;
		hsize--;
		minHeapify(ar,hsize,0);
	}
	
	display(ar,count);
}


void insertMaxHeap(int ar[]){
	
	int x;
	
	printf("\nEnter element to insert: ");
	scanf("%d",&x);
	
	if(count < SIZE){
		ar[++count] = x;
		buildMaxHeap(ar,count+1);
	}
	else{
		printf("\nCannot insert elements!");
		return;
	}
	
	display(ar,count);
}


void insertMinHeap(int ar[]){
	
	int x;
	
	printf("\nEnter element to insert: ");
	scanf("%d",&x);
	
	if(count < SIZE){
		ar[++count] = x;
		buildMinHeap(ar,count+1);
	}
	else{
		printf("\nCannot insert elements!");
		return;
	}
	
	display(ar,count);
}


//for deletion, we swap the required element with last one and decrease count, and heapify as per user's choice
void deleteMaxHeap(int ar[]){
	
	int temp,x,i,flag = 0;
	
	if(count == -1){
		printf("\nNo elements present in the heap yet!");
		return;
	}
	
	printf("\nEnter element to be deleted: ");
	scanf("%d",&x);
	
	for(i=0;i<=count;i++){
		if(ar[i] == x){
			flag = 1;
			break;
		}
	}
	
	if(flag == 0){
		printf("\nElement not found!");
		return;
	}
	
	temp = ar[count];
	ar[count] = ar[i];
	ar[i] = temp;
	
	count--;
		
	buildMaxHeap(ar,count+1);
	
	display(ar,count);
}


void deleteMinHeap(int ar[]){
	
	int temp,x,i,flag = 0;
	
	if(count == -1){
		printf("\nNo elements present in the heap yet!");
		return;
	}
	
	printf("\nEnter element to be deleted: ");
	scanf("%d",&x);
	
	for(i=0;i<=count;i++){
		if(ar[i] == x){
			flag = 1;
			break;
		}
	}
	
	if(flag == 0){
		printf("\nElement not found!");
		return;
	}
	
	temp = ar[count];
	ar[count] = ar[i];
	ar[i] = temp;
	
	count--;
	
	buildMinHeap(ar,count+1);
	
	display(ar,count);
}


void DisplayMenu(){
	printf("\nOperations:");
	printf("\n1. Insert\n2. Delete\n3. Display\n4. Display Menu\n5. Sort\n6. Exit");
}


void minHeapOperations(int ar[]){
	
	int ch;

	DisplayMenu();
	
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1)
			insertMinHeap(ar);
		else if(ch == 2)
			deleteMinHeap(ar);
		else if(ch == 3)
			display(ar, count);
		else if(ch == 4)
			DisplayMenu();
		else if(ch == 5)
			heapSortMin(ar);
		else if(ch == 6)
				break;
		else
			printf("\nInvalid options selected!");
		
	}while(ch != 6);
	
	printf("\nOperations completed!");
}


void maxHeapOperations(int ar[]){
	
	int ch;

	DisplayMenu();
	
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1)
			insertMaxHeap(ar);
		else if(ch == 2)
			deleteMaxHeap(ar);
		else if(ch == 3)
			display(ar, count);
		else if(ch == 4)
			DisplayMenu();
		else if(ch == 5)
			heapSortMax(ar);
		else if(ch == 6)
				break;
		else
			printf("\nInvalid options selected!");
		
	}while(ch != 6);
	
	printf("\nOperations completed! Exiting to HEAP MENU");
}


void main(){
	
	int ar[SIZE], n;
	
	do{
		/*
		
		Current version of the program helps us to operate on a single array, i.e,  after converting max heap operations, 
		if we select min heap, then the same array will be used for operations of min heap. Insertion and deletion happens in order
		of min heap for the same array.
		
		If a fresh array is needed, below statement(line 320) can be uncommented so that the current values can be overriden and the other
		form of heap can be tested with new array values from the start.
	
		*/
		
		//count = -1;
		
		printf("\n\nHEAP MENU\n");
		
		printf("\nWhich kind of heap is preferred? (1 - Max Heap, 2 - Min Heap, 3 - Exit)? - ");
		scanf("%d",&n);
	if(n == 1)
		maxHeapOperations(ar);
	else if(n == 2)
		minHeapOperations(ar);
	else if(n == 3);

	else
		printf("\nInvalid option selected! Please select a valid option!");

	}while(n != 3);
	
	printf("\nProgram terminated!");
}
