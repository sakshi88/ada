#include<stdio.h>
#include<conio.h>

int main()
{
   int a[20],i,j,n,key;
   printf("Enter the size of array-");
   scanf("%d",&n);
   printf("\nEnter the array elements-");
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
   for(i=0;i<n;i++)
   {
       key=a[i];
       j=i-1;
       while(j>0&&a[j]>key)
       {
	  a[j+1]=a[j];
	  j=j-1;
       }
       a[j+1]=key;
   }
   printf("array after sorting:");
   for(i=0;i<n;i++)
     printf("%d",a[i]);
   getch();
}