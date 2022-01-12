#include<stdio.h>
#include<string.h>
#define SIZE 50

void printStr(char str[], int l, int h)
{	
	int i;
    for (i = l; i <= h; ++i)
        printf("%c",str[i]);
}

int longestSubstr(char str[])
{
    
    int i,j,k, flag, len;
    int n = strlen(str);

    int maxLen = 1, init = 0;		//have the initial length as 1

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            flag = 1;
			
			len = j - i + 1;
            for (k = 0; k < len / 2; k++)	// Check palindrome
                if (str[i + k] != str[j - k])
                    flag = 0;

            if (flag && len > maxLen) {		            // If palindrome, then check for length
                init = i;
                maxLen = len;
            }
        }
    }

    printf("\nLongest palindrome substring is: ");		//if no palindrome, first letter is ouput by taking maxlength as 1
    printStr(str, init, init + maxLen - 1);

    return;
}


void main(){
	
	char str[SIZE];
	
	printf("\nEnter string: ");
	scanf("%s",str);
	
	longestSubstr(str);
	
	return;
}
