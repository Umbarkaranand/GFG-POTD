#include<stdio.h>
#define n 5
float capacity =10;

void basedprofit(float p[],float w[],float x[])
{
	float temp,weight=0.0,profit=0.0;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(p[j]<p[j+1])
			{

				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				
			}
		}
	}
	i=0;
	while(weight<=capacity)
	{
		if(weight+w[i]<=capacity)
		{
			x[i]=1;
			weight=weight+w[i];
			i++;
		
		}
		else{

		x[i]=(capacity-weight)/w[i];
		break;
	}

	}
	
	for(i=0;i<n;i++)
	{
		profit=profit+p[i]*x[i];

	}
	
	printf("\nBased on Profit PROFIT is : %f",profit);

}

void basedweight(float p[],float w[],float x[])
{
	float temp,weight=0.0,profit=0.0;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(w[j]>w[j+1])
			{
				temp=w[j+1];
				w[j+1]=w[j];
				w[j]=temp;
				
				temp=p[j+1];
				p[j+1]=p[j];
				p[j]=temp;
				
			}

		}
		
		i=0;
		while(weight<=capacity)
		{
			if(weight+w[i]<=capacity)
			{
			x[i]=1;
			weight=weight+w[i];
			i++;
		}
		else{
			x[i]=(capacity-weight)/w[i];
			break;
		}
		}
		
		for(i=0;i<n;i++)
		{
			profit=profit+(p[i]*x[i]);
		}
		
		printf("\nBased on weight PROFIT is : %f",profit);
	
	}

}
void main()
{
	float pro[n],wei[n],x[n];
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the profit : ");
		scanf("%f",&pro[i]);
		printf("Enter weight : ");
		scanf("%f",&wei[i]);
	}

	for(i=0;i<n;i++)
	{
		x[i]=0.0;
	}

	basedprofit(pro,wei,x);
    basedweight(pro,wei,x);

}
