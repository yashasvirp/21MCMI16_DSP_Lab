#include<stdio.h> 
#include<math.h>
void toh(int n) 
{ 
 int x,s,d; 
 for(x=1;x<(1<<n);x++) {
 	s = (x&(x-1))%3;
 	d = (((x |(x-1)) + 1)%3);
 	printf("Move from Pole %d to Pole %d\n",s,d); 
 }
} 
 
int main() 
{ 
 int n; 
 printf("\n Enter the Number of Disks : "); 
 scanf("%d",&n); 
 toh(n); 
 return 0; 
} 

