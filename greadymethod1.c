#include<stdio.h>

int main()
{
int input[10]={100,200,200,50,60,70,20,40,5,1};
int target=320;
int sum=0,result[0],rej[0];
int i,j=0,p=0;

for(i=0;i<10;i++)
{
	if(sum+input[i]>target)
	{
		rej[p++]=input[i];
		continue;
	}
	if(sum==target)
	{
		while(i<10)
		{
			
		}
		break;
	}
	else{
		sum=sum+input[i];
		result[j++]=input[i];
		
	}
	
}

if(sum==target)
{
	printf("Solution is : ");
	for(i=0;i<j;i++)
		printf("%d ",result[i]);
	printf("\nRejected element are : ");
	for(i=0;i<p;i++)
		printf("%d ",rej[i]);
	printf("\nNeither selected nor rejected elements are : ");

	
}
else
	printf("solution not found");

printf("\n size of j : %lu",sizeof(j));

return 0;
}
