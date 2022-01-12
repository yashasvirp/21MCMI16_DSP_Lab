#include<stdio.h>
#include<ctype.h>
char arr[100];
int top=-1;

void push(char c)
{
	arr[++top]=c;
}
char pop()
{
	char t;
	
	if(top==-1)
		return -1;
		
	t=arr[top--];
	return t;
}
int priority(char x)
{
	if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
	
}


int main()
{
	char arr1[1000];
	char x;
	int i;
	printf("\nEnter the String: ");
	scanf("%s",arr1);
	printf("\nPostfix expression: ");
	for(i=0;arr1[i]!='\0';i++)
	{
		if(isalnum(arr1[i]))
			printf("%c",arr1[i]);
		
		else if(arr1[i] == '(')
				push(arr1[i]);
            
        else if(arr1[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }

		else
		{
		        while(priority(arr[top])>=priority(arr1[i]))
				printf("%c",pop());
				
		        push(arr1[i]);
	    }
	}
	while(top!=-1)
			printf("%c",pop());	
}
