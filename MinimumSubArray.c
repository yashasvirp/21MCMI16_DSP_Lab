#include<stdio.h>
  void subarray(int arr[], int x, int n)
{
    int minLen = n + 1,i,j,k,flag=0,start,end;
 
     for (i=0;i<n; i++)
     {
          int sum = arr[i];
 
          if (sum > x){
          	printf("\n The subarray is: %d",arr[i]);
          	return;
		  }
		  	
 
          for (j=i+1; j<n; j++)
          {
              sum += arr[j];
 
              if (sum > x && (j - i + 1) < minLen){
              		minLen = (j - i + 1);
              		start = i;
              		end = j;
              		flag = 1;
			  }
                 
          }
     }
     
     if(flag == 0){
     	printf("\nNo such subarray exists");
     	return;
	 }
	 
	 printf("\nThe subarray is: ");
     for(k=start;k<=end;k++)
		printf("%d ",arr[k]);
}

int main()
{
	int arr[100], sum, n, i;
	printf("\nEnter array size: ");
	scanf("%d",&n);
	printf("\nEnter elements: ");
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("\nThe array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		
	printf("\nEnter sum value: ");
	scanf("%d",&sum);
	
    subarray(arr,sum,n);
	
}
