#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define STRSIZE 25
#define NODES 10

//leaf nodes for frequency - L4
typedef struct leaf{
	int freq;
}leaf;

//structure for copying into array
typedef struct arr{
	char words[STRSIZE];
	int freq;
}arr;

//for words - L3
typedef struct words{
	char w[STRSIZE];
	struct leaf *l;
	int lim;
}words;

//for categories - L2
typedef struct categ{
	char str[STRSIZE];
	struct words *w[NODES];
	int cat;
}categ;

//strings root
typedef struct root{
	char st[STRSIZE];
	struct categ *child[NODES];
}root;


struct root *r1 = NULL;

//creating string categ
struct categ *createStringcateg(char s[]){
	int i;
	struct categ *temp = (struct categ*)malloc(sizeof(struct categ));
	strcpy(temp->str,s);
	temp->cat = -1;
	for(i-0;i<NODES;i++)
		temp->w[i] = NULL;
	return temp;
}

struct words *createWords(char s[], int lim){
	
	struct words *temp;
	
	temp = (struct words*)malloc(sizeof(struct words));
	strcpy(temp->w,s);
	temp->l = NULL;
	temp->lim = lim;
	return temp;
}

struct root *createRoot(){
	int i;
	struct root *temp = (struct root*)malloc(sizeof(struct root));
	strcpy(temp->st,"Words");
	for(i=0;i<NODES;i++)
		temp->child[i] = NULL;
	
	return temp;
}

struct leaf *createLeaf(){
	struct leaf *l = (struct leaf*)malloc(sizeof(struct leaf));
	l->freq = 2;
	return l;
}

bool checkCat(char s[]){
	int i;
	struct root *temp = r1;
	
	while(temp->child[i] != NULL && i < NODES){
		if(strcmp(temp->child[i]->str,s)==0)
			return true;
		i++;
	}
	return false;
}

int getCat(char *s){
	struct root *temp = r1;
	int i=0;
	
	if(temp == NULL){
		printf("\nNo Tree present");
		return;
	}
	
	if(checkCat(s) == true){
			while(strcmp(temp->child[i]->str,s) != 0){
				i++;
		}
		return i+1;
	}
	
	return -1;
}

struct root *insertCat(struct root *r1, char s[]){
	
	struct root *temp = r1;
	int i = 0,j;

	if(temp == NULL){
		printf("\nNo Tree created!");
		return NULL;
	}
	if(strcmp(temp->st,"Words")==0){
		
		if(checkCat(s))											//Check if category exists
			printf("\nCategory already present!");
		else{													//insert category
			while(i < NODES){
				if(temp->child[i] == NULL)
					break;
				i++;
			}
			if(i == NODES)
				printf("\nNo more categories to enter!");
			else{
				temp->child[i] = createStringcateg(s);
				temp->child[i]->cat = i+1;
			//	printf("\nCategory number is %d",i);
				for(j=0;j<NODES;j++)
					temp->child[i]->w[j] = NULL;
			}
		}
	}
	return temp;
}

void enterWord(char s[], int i){
	int j = 0,lim;
	struct root *temp = r1;
	struct words *word;
	
	while(j < NODES){
		if(temp->child[i]->w[j]!= NULL)	{
			if(strcmp(temp->child[i]->w[j]->w,s) == 0) {		//if word already present
					if(temp->child[i]->w[j]->lim == 1){			//if word limit is only one
					printf("\nFrequency exceeded, can't enter this word again!");
					return;
					}
					else{	
							if(temp->child[i]->w[j]->l == NULL)				//if word present previously for the first time
							{
								temp->child[i]->w[j]->l = createLeaf();		//create word for the first time with frequency 2
								if(temp->child[i]->w[j]->l->freq <= temp->child[i]->w[j]->lim)		//check limit
									printf("\nAlready present. Frequency updated. Frequency is %d",temp->child[i]->w[j]->l->freq);
								else
									printf("\nFrequency exceeded, can't enter this word again!");
							}
							else{
								if(temp->child[i]->w[j]->l->freq < temp->child[i]->w[j]->lim){
									temp->child[i]->w[j]->l->freq++;
									printf("\nAlready present. Frequency updated. Frequency is %d",temp->child[i]->w[j]->l->freq);
								}
								else
									printf("\nFrequency exceeded, can't enter this word again!");
							}
							break;
					}
			}
		}
		else{	
		printf("\nEnter word limit: ");														//create word for the first time;
		scanf("%d", &lim);
		word = createWords(s,lim);
		temp->child[i]->w[j] = word;
		temp->child[i]->w[j]->l = NULL;
		break;													//assign leaf to NULL as it is the first and only value
	}	
		j++;
	}
	if(j == NODES){											//if full capacity
		printf("\nCannot enter any more words!");
		return;
	}
return;
}

struct root *insertWord(struct root *r1){
	
	struct root *temp = r1;
	int i = 0,l;
	char s[STRSIZE],cat[STRSIZE];

	if(strcmp(temp->st, "Words") == 0){
	
		printf("\nEnter word: ");
		scanf(" %[^\t\n]s",s);
		printf("\nEnter category to be inserted in: ");
		scanf(" %[^\t\n]s",cat);
		i = getCat(cat);
		if(i == -1)
			printf("\nCategory not present!");
		else{
			enterWord(s,i-1);
		}
	}
	else
		printf("\nImproper root value! Cannot insert word!");
	return temp;
}

void DisplayLeaf(){
	struct root *temp = r1;
	int i = 0, j = 0;
	while(i < NODES){
		if(temp->child[i] != NULL){
				printf("\n\nCategory : %s",temp->child[i]->str);
			printf("\nWords are: ");
			j = 0;
			while(temp->child[i]->w[j] != NULL && j < NODES){
				printf("\n%s",temp->child[i]->w[j]->w);
				j++;
			}
		}
		else{
			printf("\n\nNo further category present!");
			break;
		}
		
		i++;
	}
}

void DisplayCat(){
	struct root *temp = r1;
	int i = 0;
	if(temp->child[0] == NULL){
		printf("\nNo Categories yet!");
		return;
	}
	
	while(i < NODES){
		if(temp->child[i] != NULL){
				printf("\n%d - %s",i+1,temp->child[i]->str);
		}
		i++;
	}
}

void sortAndDisplay(struct arr sortedArr[], int k){
	int i = 0, j = 0, t;
	char temp[STRSIZE];
	/*
	for(i=0;i<k;i++){
			printf("\n%s - Frequency - %d",sortedArr[i].words,sortedArr[i].freq);
	}
	
	*/
	
	for(i=0;i<k;i++){
		for(j=0;j<k-i-1; j++){
			if(sortedArr[j].freq < sortedArr[j+1].freq){
				strcpy(temp,sortedArr[j].words);
				strcpy(sortedArr[j].words,sortedArr[j+1].words);
				strcpy(sortedArr[j+1].words,temp);
				
				t = sortedArr[j].freq;
				sortedArr[j].freq = sortedArr[j+1].freq;
				sortedArr[j+1].freq = t;
			}
		}
	}
	
	for(i=0;i<k;i++){
			printf("\n%s - Frequency - %d",sortedArr[i].words,sortedArr[i].freq);
	}
}

bool checkWord(char s[]){
	struct root *temp = r1;
	int i = 0,j = 0;
	
	while(i < NODES){
		if(temp->child[i] != NULL){
			while(j < NODES){
				if(temp->child[i]->w[j] != NULL){
					if(strcmp(temp->child[i]->w[j]->w,s) == 0)
						return true;
				}
				else
					break;
				j++;
			}
		}
		else
			break;
		i++;
	}
	return false;
}

void Depth(){
	
	char s[STRSIZE];
	
	printf("\nEnter word: ");
	scanf(" %[^\t\n]s",s);
	if(strcmp(s,"Words") == 0)   //if word is root
		printf("\nDepth is 0");
	else if(checkCat(s)){				//if word is a category
		printf("\nDepth of word is 1");
	}
	else if(checkWord(s))			//if a word is under a category
		printf("\nDepth is 2");
	else
		printf("\nNo such word exists!");
}

void Displayfreq(){
	struct root *temp = r1;
	struct arr sortedArr[NODES];
	int i = 0, j = 0,k = 0;
	while(i < NODES){
		
		if(temp->child[i] != NULL){
			j = 0;
			while(j < NODES){
				if(temp->child[i]->w[j] != NULL){
					strcpy(sortedArr[k].words,temp->child[i]->w[j]->w);
					if(temp->child[i]->w[j]->l != NULL)
						sortedArr[k].freq = temp->child[i]->w[j]->l->freq;
					else
						sortedArr[k].freq = 1;
					k++;
				}
				else 
					break;
				j++;
			}
		}		
		i++;
	}
	sortAndDisplay(sortedArr,k);
}

void degreeCategory(char s[]){
	struct root *temp = r1;
	int i = 0,flag = 0,j = 0;
	while(i < NODES){
		if(temp->child[i]!=NULL)
			if(strcmp(temp->child[i]->str,s) == 0){
				flag = 1;
				break;
			}
		i++;
	}
	if(flag == 0){
		printf("\nCategory not found!");
		return;
	}
	while(temp->child[i]->w[j] != NULL && j < NODES)
		j++;

	printf("\nDegree of category is %d",j);
}

void degreeRoot(struct root *r1){
	int i = 0;
	struct root *temp = r1;
	while(i < NODES){
		if(temp->child[i] == NULL)
			break;
			i++;
	}
	printf("\nDegree of root: %d", i);
}

void DisplayMenu(){
	printf("\nTree Operations:");
	printf("\n1. Insert Category\n2. Insert word\n3. Display leaves\n4. Display Categories\n5. Degree of category\n6. Degree of Root\n7. Display words according to frequency\n8. Display depth of a word\n9. Display Menu\n10. Exit");
}

void main(){
	
	int x,ch;
	char s[STRSIZE],ans;
	r1 = createRoot();
	printf("\nRoot is : %s", r1->st);
	DisplayMenu();
	
	do{
	
		if(r1 == NULL || strcmp(r1->st,"Words") != 0){
			printf("\nRoot is null/improper, no further operations can be performed!");
			return;
		}
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1){
			printf("\nEnter category name: ");
			scanf(" %[^\t\n]s", s);
			r1 = insertCat(r1,s);
		}
		else if(ch == 2){
			r1 = insertWord(r1);
		}
		else if(ch == 3)
			DisplayLeaf();
		else if(ch == 4)
			DisplayCat();
		else if(ch == 5){
			printf("\nEnter Category: ");
			scanf(" %[^\t\n]s",s);
			degreeCategory(s);
		}
		else if(ch == 6)
			degreeRoot(r1);
		else if(ch == 7)
			Displayfreq();
		else if(ch == 8)
			Depth();
		else if(ch == 9)
			DisplayMenu();
		
	}while(ch != 10);
	
	printf("\nOperations completed Successfully!");
	return;
}
