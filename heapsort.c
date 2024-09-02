#include<stdio.h>
int size=0;
int arr[10];

void heapify(int a[],int i)
{
	if(size==0)
	printf("%d ",a[size]);
	else{
	int m;
	m=i;
	int l=2*i+1;
	int r=2*i+2;	

	if(l<=size && a[l]<a[m])
		m=l;

	if(r<=size && a[r]<a[m])
		m=r;

	if(m!=i)
	{
		
		 int temp = a[i];  
      		 a[i] = a[m];  
       		 a[m] = temp;  
	}

	}

}

void insert(int a[],int d)
{
	if(size==0)
	{
		a[size]=d;
		size++;
	}
	else{
		a[size]=d;
		size++;
		for(int i=(size/2)-1;i>=0;i--)
		{
			heapify(arr,i);
		}
	}
	
}


int main()
{

insert(arr,3);
insert(arr,4);
insert(arr,1);
insert(arr,6);
insert(arr,7);


return 0;
}
