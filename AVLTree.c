#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *l,*r;
	int bf;
}node;

struct node *root = NULL;

int height(struct node *root){
	if(!root)
		return -1;
	else
		return root->bf;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Create a node
struct node *newNode(int key) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = key;
  temp->l = NULL;
  temp->r = NULL;
  temp->bf = 1;
  return (temp);
}

// Right rotate
struct node *rightRotate(struct node *y) {
  struct node *x = y->l;
  struct node *T2 = x->r;

  x->r = y;
  y->l = T2;

  y->bf = max(height(y->l), height(y->r)) + 1;
  x->bf = max(height(x->l), height(x->r)) + 1;

  return x;
}

// l rotate
struct node *leftRotate(struct node *x) {
  struct node *y = x->r;
  struct node *T2 = y->l;

  y->l = x;
  x->r = T2;

  x->bf = max(height(x->l), height(x->r)) + 1;
  y->bf = max(height(y->l), height(y->r)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct node *N) {
	
	int balance;
	
  if (N == NULL)
    return 0;
  return height(N->l) - height(N->r);
}

// Insert node
struct node *insertNode(struct node *temp, int key) {
	
	int balance;
  // Find the correct position to insertNode the node and insertNode it
  if (temp == NULL)
    return (newNode(key));

  if (key < temp->data)
    temp->l = insertNode(temp->l, key);
  else if (key > temp->data)
    temp->r = insertNode(temp->r, key);
  else
    return temp;

  // Update the balance factor of each node and
  // Balance the tree
  temp->bf = 1 + max(height(temp->l),height(temp->r));

  balance = getBalance(temp);
  if (balance > 1 && key < temp->l->data)
    return rightRotate(temp);

  if (balance < -1 && key > temp->r->data)
    return leftRotate(temp);

  if (balance > 1 && key > temp->l->data) {
    temp->l = leftRotate(temp->l);
    return rightRotate(temp);
  }

  if (balance < -1 && key < temp->r->data) {
    temp->r = rightRotate(temp->r);
    return leftRotate(temp);
  }

  return temp;
}

struct node *minValueNode(struct node *temp) {
  struct node *current = temp;

  while (current->l != NULL)
    current = current->l;

  return current;
}

// Delete a nodes
struct node *deleteNode(struct node *root, int key) {
  // Find the node and delete it
  
  int balance;
  
  if (root == NULL)
    return root;

  if (key < root->data)
    root->l = deleteNode(root->l, key);

  else if (key > root->data)
    root->r = deleteNode(root->r, key);

  else {
    if ((root->l == NULL) || (root->r == NULL)) {				//Node with single child
      struct node *temp = root->l ? root->l : root->r;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct node *temp = minValueNode(root->r);			

      root->data = temp->data;

      root->r = deleteNode(root->r, temp->data);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->bf = 1 + max(height(root->l),height(root->r));

  balance = getBalance(root);
  if (balance > 1 && getBalance(root->l) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->l) < 0) {
    root->l = leftRotate(root->l);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->r) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->r) > 0) {
    root->r = rightRotate(root->r);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void preorder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->l);
    preorder(root->r);
  }
}

void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->l);
    postorder(root->r);
    printf("%d ", root->data);
  }
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->l);
    printf("%d ", root->data);
    inorder(root->r);
  }
}

void CurrentLevel(struct node *root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root -> data);
  else if (level > 1) {
    CurrentLevel(root -> l, level - 1);
    CurrentLevel(root -> r, level - 1);
  }
}

void LevelOrder(struct node *root) {
  int h = ht(root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel(root, i);
}

int ht(struct node* node) {
  if (node == NULL)
    return 0;
  else {
    int lheight = height(node -> l);
    int rheight = height(node -> r);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}

int sumLeft(struct node *root){
	int sum = 0;
	
	if(root == NULL)
		return 0;
	
	sum += root->data + sumLeft(root->l) + sumLeft(root->r);
	
	return sum;
}

void DisplayMenu(){
	printf("\nOperations Menu:");
	printf("\n1. Insert\n2. Delete\n3. Display inorder\n4. Display Preorder \n5. Display postorder\n6. Display Level order\n7. Display Sum of Left subtree nodes\n8. Exit");
}


void main(){
	int i = 0,x,ch;
	
	DisplayMenu();

	do{
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1){
			printf("\nEnter element:");
			scanf("%d", &x);
			root = insertNode(root, x);
			if(root == NULL)
				printf("\nOperation failed");
		}
		else if(ch == 2){
			printf("\nEnter element:");
			scanf("%d", &x);
			root = deleteNode(root,x);
			if(root == NULL)
			printf("\nOperation failed");
		}
		else if(ch == 3){
				printf("\nInorder:\n");
				inorder(root);
		}
		else if(ch == 4){
				printf("\nPreorder:\n");
				preorder(root);
		}
		else if(ch == 5){
				printf("\nPostorder:\n");
				postorder(root);
		}
		else if(ch == 6){
				printf("\nLevel order:\n");
				LevelOrder(root);
		} 
		else if(ch ==7)
					printf("\nSum of Left subtree nodes: %d\n",sumLeft(root->l));
		else
			printf("\nEnter a valid choice!");	
		
	}while(ch != 8);
}


