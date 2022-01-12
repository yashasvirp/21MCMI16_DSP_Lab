#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 15
typedef struct node{
	char data;
	struct node *l,*r;
};

struct node *root = NULL;
struct node *construct(struct node*, char[], int, int);
void main(){
	int h,i,n;
	char ar[SIZE];
	
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	
	if(n < 1 || n > SIZE){
		printf("\nNot a valid  quantiity");
		return;
	}
	
	printf("\nEnter input: ");
		scanf("%s",ar);
	
	root = construct(root,ar,0,n);
	
	printf("\ninorder: ");
	inorder(root);
	
	printf("\npreorder: ");
	preorder(root);
	
	printf("\npostorder: ");
	postorder(root);	
	
	printf("\nheight of tree : %d", height(root)-1);
	
	printf("\nThe tree is: \n");
	print2D(root);
}

struct node *createNode(char data){

		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->l = NULL;
		temp->r = NULL;
	
	return temp;
}

struct node *construct(struct node *root, char ar[], int i, int n){
		
	if(i<n){
		struct node *temp = createNode(ar[i]);
		root = temp;
		root->l = construct(root->l, ar, 2*i + 1, n);
		root->r = construct(root->r, ar, 2*i + 2, n);
	}
	
	return root;
}

void preorder(struct node *root){
	if(root == NULL)
		return;
	
	preorder(root->l);
	printf("%c\t",root->data);
	preorder(root->r);
}

void inorder(struct node *root){
	if(root == NULL)
		return;

	printf("%c\t",root->data);
	inorder(root->l);
	inorder(root->r);
}

void postorder(struct node *root){
	if(root == NULL)
		return;
	
	postorder(root->l);
	postorder(root->r);
	printf("%c\t",root->data);
}

int height(struct node *root){
	if(root == NULL)
		return 0;
	return 1 + max(height(root->l),height(root->r));
}

int max(int a, int b){
	return a>b?a:b;
}

//Prints the tree vertically
void print(struct node *root, int space)
{
    int i;
    if (root == NULL)
        return;
     space += SIZE;
 
    print(root->r, space); //right child first
 
    printf("\n");
    for (i = SIZE; i < space; i++)
        printf(" ");
    printf("%c\n",root->data);
 
    print(root->l, space); //left child next
}
 
void print2D(struct node *root)
{
    print(root, 0); //initial space as 0
}
