#include<stdio.h>
#include<stdbool.h>
#define SIZE 10

int Q[SIZE], S[SIZE], f = -1, r = -1, top = -1, G[SIZE][SIZE];
int vis[SIZE];

bool QEmpty(){
	if(f > r)
		return true;
	return false;
}

void enqueue(int q[], int ele, int n){
	
	if(r == n){
		printf("\nOverflow! Cannot insert!");
		return;
	}
	
	if(r == -1){
		q[++r] = ele;
		f++;
	}
	else
		q[++r] = ele;	
}

int dequeue(int Q[]){
	
	if(f > r || f == -1)
		return -1;
	
	return Q[f++];
}

void DisplayGraph(int G[][SIZE], int v){
	
	int i,j;
	
	for(i = 0; i < v; i++){
		printf("\n");
		for(j = 0; j < v; j++)
			printf("\t%d",G[i][j]);
	}
}

void BFS(int v, int n){

	int i,j;
	
	enqueue(Q,v,n);
	vis[v] = 1;
	
	j = dequeue(Q);
	
	if(j != -1) 
		printf("\t%d",j);
		
	while(j != -1)
	{
		for(i = 0; i < n; i++)
		if((G[j][i])&&(vis[i] == 0)) {
			enqueue(Q,i,n);
			vis[i] = 1;
		}
		
		j = dequeue(Q);
		
		if(j != -1) 
			printf("\t%d",j);
	}
	
	for(i = 0; i < n; i++)
		if(vis[i] == 0) 
			BFS(i,n);
}

void DFS(int v, int n){		//we don't have to use an external stack as we can have function call stack that can be used for printing

	int j;
	
	printf("\t%d",v);
	
	vis[v] = 1;
	
	for(j=0;j<n;j++)
	    if(!vis[j]&&G[v][j]==1)
	        DFS(j,n);
	        
}

void DisplayMenu(){
	printf("\n1. BFS\n2. DFS\n3. Display Graph Matrix\n4. Display Menu\n5. Exit ");
}

void main(){
	
	int i,j,v,ch,n,x;


	printf("\nEnter number of nodes: ");
	scanf("%d",&v);
	
	printf("\n Enter values for Graph:");

	for(i = 0; i < v; i++)		//Initializing loopy nodes to 0, i.e. not accepting loops
		G[i][i] = 0;

	for(i = 0; i < v; i++){
		
		printf("\nFor vertex %d: ",i);
		
		for(j = i+1; j < v; j++){
			
			do{
				printf("\nWould you want an edge between %d and %d?(0 - no/1 - yes): ",i,j);
				scanf("%d",&ch);
				
				if(ch != 0 && ch != 1)
					printf("\nEnter a valid choice!");

			}while(ch != 0 && ch != 1);
			
			
			if(ch){
				G[i][j] = 1;		//Initialising a symmetric matrix
				G[j][i] = 1;
			}
			else {
				G[i][j] = 0;
				G[j][i] = 0;
			}
		}
			
	}
	
	DisplayMenu();
	do{
		
		for(i = 0; i < v; i++)		//we use 0 for unvisited, 1 for visited
		vis[i] = 0;
		
		vis[0] = 1;				//source node is visited

		printf("\nEnter your choice:");
		scanf("%d",&n);
		
		if(n == 1){
			
			do{
				printf("\nEnter source vertex (values between 0 and %d):  ",v-1);
				scanf("%d",&x);
				
				if(x < && x >= v)
					printf("\nEnter a valid choice!");
				
			}while(x >=0 && x < v);
			
			printf("\nBFS is: ");
			BFS(x,v);
		}
		else if(n == 2){
			do{
				printf("\nEnter source vertex (values between 0 and %d):  ",v-1);
				scanf("%d",&x);
				
				if(x < && x >= v)
					printf("\nEnter a valid choice!");
				
			}while(x >=0 && x < v);
			
			printf("\nDFS is: ");
			DFS(x,v);
		}
		else if(n == 3)
			DisplayGraph(G,v);
		else if(n == 4)
				DisplayMenu();
		else if(n == 5)
					break;
		else
			printf("\nEnter a valid choice!");
	}while(n != 5);
	
	printf("\nOperations completed succesfully!");
	
}

