#include<stdio.h>
#include<stdbool.h>
#define SIZE 100
int top = -1;
char ar[SIZE];
bool isValid(char[]);
void main(){
	//char ar[SIZE];
	int i;
	
	printf("\nEnter string: ");
	scanf("%s",ar);
	
	for(i = 0; ar[i] != '\0'; i++)
		if(ar[i]!= '(' && ar[i]!='{' && ar[i]!='[' && ar[i]!=']' && ar[i]!='}' && ar[i]!=')' ){
			printf("\nInvalid input!");
			return;
		}
		
	printf("\n%s", isValid(ar)? "TRUE": "FALSE");
	
	 
}

int priority(char c){
	if(c == '(' || c == ')')
		return 2;
	else if(c == '[' || c == ']')
		return 1;
	return 0;
}

bool isEmpty(){
	if(top == -1)
		return true;
	return false;
}

char pop(){
	if(isEmpty()){
		//printf("\nUnderflow! Unsuccesful operation!");
		return '0';
	}
	
	return ar[top--];
}

bool isFull(){
	if(top == SIZE-1)
		return true;
		
	return false;
}


bool push(char c){
	if(isFull()){
		//printf("\nOverflow! unsuccesful operation!");
		return false;
	}
	ar[++top] = c;
	return true;
}


bool isValid(char ar[]){
	char c,ip;
	int i=0;
	while( (c=ar[i]) != '\0'){
		if(c == '(' || c == '{' || c == '[')
			if(!push(c)){
				return false;
			}
		
		if(c == ']' || c == '}' || c == ')'){
			ip = pop();
			if(priority(c) != priority(ip)){
				printf("\nInvalid paranthesis!");
				return false;
			}
		}
		i++;
	}
	if(c == '\0' && isEmpty()){
		printf("\nValid paranthesis");
		return true;
	}
	else{
		printf("\nInvalid Paranthesis!");
		return false;
	}
		
}







