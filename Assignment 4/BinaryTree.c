#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct node{
	int data;
	struct node *l,*r;
};

struct node *root = NULL;
struct node *construct(struct node*, int[], int, int);
void main(){
	int ar[SIZE],h,i,n;
	
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	
	if(n < 1 || n > SIZE){
		printf("\nNot a valid  quantiity");
		return;
	}
	
	printf("\nEnter input nodes: ");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	
	root = construct(root,ar,0,n);
	
	printf("\ninorder: ");
	inorder(root);
	
	printf("\npreorder: ");
	preorder(root);
	
	printf("\npostorder: ");
	postorder(root);	
	
	printf("\nheight of tree : %d", height(root));
	
	printf("\nThe tree is: \n");
	print2D(root);
}

struct node *createNode(int data){

		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->l = NULL;
		temp->r = NULL;
	
	return temp;
}

struct node *construct(struct node *root, int ar[], int i, int n){
		
	if(i<n){
		struct node *temp = createNode(ar[i]);
		root = temp;
		root->l = construct(root->l, ar, 2*i + 1, n);
		root->r = construct(root->r, ar, 2*i + 2, n);
	}
	
	return root;
}

void inorder(struct node *root){
	if(root == NULL)
		return;
	
	inorder(root->l);
	printf("%d\t",root->data);
	inorder(root->r);
}

void preorder(struct node *root){
	if(root == NULL)
		return;

	printf("%d\t",root->data);
	preorder(root->l);
	preorder(root->r);
}

void postorder(struct node *root){
	if(root == NULL)
		return;
	
	postorder(root->l);
	postorder(root->r);
	printf("%d\t",root->data);
}

int height(struct node *root){
	if(root == NULL)
		return -1;
	return 1 + max(height(root->l),height(root->r));
}

int max(int a, int b){
	return a>b?a:b;
}

//Prints the tree vertically
void print2DUtil(struct node *root, int space)
{
    int i;
    
    if (root == NULL)
        return;
    
	space += SIZE;
 
    print2DUtil(root->r, space); //right child first
 
    printf("\n");
    for (i = SIZE; i < space; i++)
        printf(" ");
    printf("%d\n",root->data);
 
    print2DUtil(root->l, space); //left child next
}
 
void print2D(struct node *root)
{
    print2DUtil(root, 0); //initial space as 0
}

