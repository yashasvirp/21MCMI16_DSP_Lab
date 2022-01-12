#include <stdio.h>
#include<stdlib.h>
#define TABLE 10

int ht[TABLE] = {NULL}, count = 0,maxCollision = 1000;


//simple hash function, h1(k) = k%m
int hash1(int key){
	
	int h;
	
	h = key % TABLE;
	
	return h;
}

//next hash function, h2(k) = 2k%m
int hash2(int key){
	
	int h;
	
	h = 2*key % TABLE;
	
	return h;
}	

int safeMod(int a, int b) {
     int m = a % b;
     return (m >= 0) ? m : (m+b);
}

void insert() {

	int key,h1,i=0,j,h2;
	
	if(count == TABLE){
		printf("\nTABLE FULL! Cannot insert anymore!");
		return;
	}
	
	printf("\nEnter element to be inserted: ");
	scanf("%d",&key);
	
	h1 = hash1(key);
	
	j = h1;
	
	if(ht[j] != NULL)
		h2 = hash2(key);
	
	while(ht[j] != NULL) {
		
		if(ht[j] != NULL)
			j = safeMod((h1 + h2*i),TABLE);
		
		if(ht[j] == NULL)
			break;
		else 
			i++;
			
		if(i == maxCollision){
			printf("\nMax collision occured. Cannot insert the element!");
			return;
		}

	}
	
	ht[j] = key;
	count++;
	printf("\nSuccessfully inserted element %d at position %d, collision number %d, count %d",key,j,i,count);
	
}

//for deletion, sequential probing is used to delete the elements
void delete(){
	
	int key, index,i;
	
	if(count == 0){
		printf("\nTABLE EMPTY! Cannot delete anymore!");
		return;
	}
	
	printf("\nEnter the element to be deleted:");
	scanf("%d",&key);
	
	index = hash1(key);
	
	if(ht[index] == NULL){
		printf("\nElement not found!");
		return;
	}
	
	i = index;
	
	do{
	
		if(ht[i] == key){
			ht[i] = NULL;
			count--;
			printf("\nElement %d deleted at position %d",key,i);
		}
		
		i = (i+1) % TABLE;
		
		
	}while(i != index);

}

//for searching, sequential probing is used
	
void search() {
	int key,index,i,flag = 0;
	
	printf("\nEnter element to be searched: ");
	scanf("%d",&key);
	
	index = hash1(key);
	
	if(ht[index] == NULL){
		printf("\nElement not found!");
		return;
	}
	
	i = index;
	
	do{
		
		if(ht[i] == key){
			printf("\nElement found at position %d",i);
			flag = 1;
		}

		i = (i+1) % TABLE;
		
	}while(i != index);

	if(flag == 0)
		printf("\nElement not found!");
	
}


void display() {
	int i;
	
	printf("\nElements in the hash table are: \n");
	
	printf("\n(Index <=> value format)\n");
	for(i=0;i< TABLE; i++){
		if(ht[i] == NULL)
			printf("\n%d <====> NULL",i);
		else
			printf("\n%d <====> %d",i,ht[i]);			
	}
}

void loadfactor(){
	double lf;
	int i = 0,c = 0;
	while(i <= TABLE){
		if(ht[i] != NULL)
			c += 1;
		i++;
	}
	
	lf = (double)(c-1)/(double)TABLE;
		
	printf("\nLoad factor is %lf",lf);
}


int main() {
	int ch,i;
	do
	{
		printf("\n\n1.Insert\n2.Display \n3.Search \n4.Delete \n5.load factor\n6.Exit \n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch==1)
			insert();
		else if(ch==2)
			display();
		else if(ch==3)
			search();
		else if(ch==4)
			delete();
		else if(ch==6)
			break;
		else if(ch==5)
			loadfactor();
		else	
			printf("\nEnter a valid choice!");
	}while(ch != 6);
	
	printf("\nOperations completed!\n");
}
