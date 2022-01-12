#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct charStack
{
    char data;
    struct charStack *next;
};

struct charStack *charStackTop=NULL;

struct treeNodeStack
{
    struct treeNode *node;
    struct treeNodeStack *next;
};

struct treeNode
{
    char c;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNodeStack *nodeStackTop= NULL;

struct treeNode *createTreeNode(char value)
{
    struct treeNode *t = (struct treeNode *)malloc(sizeof(struct treeNode));
    t->c = value;
    t->left = t->right = NULL;
    return t;
}

void pushCharStack(char c)
{
    struct charStack *temp = (struct charStack *)malloc(sizeof(struct charStack));
    temp->data = c;
    temp->next = NULL;
    if(!charStackTop)
    {
        charStackTop = temp;
    }
    else
    {
        temp->next = charStackTop;
        charStackTop = temp;
    }
}

void pushTreeNodeStack(struct treeNode *t)
{   
    struct treeNodeStack *temp = (struct treeNodeStack *)malloc(sizeof(struct treeNodeStack));
    temp->node = t;
    temp->next = NULL;
    if(!nodeStackTop)
        nodeStackTop = temp;
    else
    {
        temp->next = nodeStackTop;
        nodeStackTop = temp;
    }
}

bool isNodeStackEmpty()
{
    return nodeStackTop == NULL;
}

bool isCharStackEmpty()
{
    return charStackTop == NULL;
}

char popCharStack()
    {
        struct charStack *cs = charStackTop;
        charStackTop = charStackTop->next;
        return cs->data;
    }

struct treeNode *popNodeStack()
{
    struct treeNodeStack *tn = nodeStackTop;
    nodeStackTop = nodeStackTop->next;
    return tn->node;
}

bool isOperand(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='B') || (c>='0' && c<='9'))
        return true;
    return false;
}

int operatorPriority(char c)
{
    if(c=='^')
        return 4;
    else if(c=='/')
        return 3;
    else if(c=='*')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-')
        return true;
    return false;
}

void postorder(struct treeNode *ptr)
{
    if(ptr)
    {   
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %c ",ptr->c);
    }
}

void preorder(struct treeNode *ptr)
{
    if(ptr)
    {
        printf(" %c ",ptr->c);
        preorder(ptr->left);
        preorder(ptr->right);
                
    }
}

bool verifyInfix(char str[],int size)
{   
    int parenCount = 0;
    int i;
    bool isValid = true;
    if(isOperator(str[0]) || isOperator(str[size-1]))
    {
        isValid = false;
        return isValid;
    }
    for(i=1; i<size-1; i++)
    {
        if(isOperator(str[i]))
        {
            if(!isOperand(str[i-1]) || !isOperand(str[i+1]))
                isValid = false;
        }
        if(str[i] == '(')
            parenCount++;
        if(str[i] == ')' && parenCount == 0)
            isValid = false;
        if(str[i] == ')' && parenCount > 0)
            parenCount--;
    }
    return isValid;
}

void main()
{   
    char str[100];
    struct treeNode *temptn, *treeroot;
    printf("\nEnter String: ");
    scanf("%s",str);
    if(verifyInfix(str,strlen(str)))
    {
        printf("\nValid Infix expression");
        int i;
        for(i=0; i<strlen(str); i++)
        {
            if(str[i] == '(')
                pushCharStack(str[i]);
            else if(isOperand(str[i]))
            {
                struct treeNode *tn = createTreeNode(str[i]);
                pushTreeNodeStack(tn);
            }
            else if(isOperator(str[i]))
            {
                while(!isCharStackEmpty() && charStackTop->data != '(' && operatorPriority(charStackTop->data) >= operatorPriority(str[i]))
                {
                    temptn = createTreeNode(popCharStack());
                    temptn->right = popNodeStack();
                    temptn->left = popNodeStack();
                    pushTreeNodeStack(temptn);
                    
                }
                pushCharStack(str[i]);
            }
            else if(str[i] == ')')
            {
                while(!isCharStackEmpty() && charStackTop->data != '(')
                {
                    temptn = createTreeNode(popCharStack());
                    temptn->right = popNodeStack();
                    temptn->left = popNodeStack();
                    pushTreeNodeStack(temptn);
                }
                popCharStack();
            }
        }
        if(i==strlen(str) && !isCharStackEmpty())
        {
            while(!isCharStackEmpty())
                {
                    temptn = createTreeNode(popCharStack());
                    temptn->right = popNodeStack();
                    temptn->left = popNodeStack();
                    pushTreeNodeStack(temptn);
                }
        }
        treeroot = popNodeStack();
        printf("\nPrefix is: ");
        preorder(treeroot);
        printf("\nPostfix is: ");
        postorder(treeroot);
        printf("\n");
    }
    else
        printf("\nInvalid Expression!");
}
