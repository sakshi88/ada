#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int p,int r)
{
	int key,i,j;
	key=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=key)
		{
			int t;
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}

void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{

		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int main()
{
	int i,j,a[90],n;
	printf("Enter the array size\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("Sorted array is");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}

	return 0;
}