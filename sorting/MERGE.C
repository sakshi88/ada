#include<stdio.h>
#include<conio.h>

void merge(int a[],int p,int q,int r)
{
   int n1=q-p+1;
   int n2=r-q;
   int l[10],r1[10],i,j,k;
   for(i=1;i<n1;i++)
      l[i]=a[p+i-1];
   for(j=1;j<n2;j++)
      r1[j]=a[q+j];
   i=1;
   j=1;
   l[n1+1]=NULL;
   r1[n2+1]=NULL;
   for(k=p;k<=r;k++)
   {
      if(l[i]<=r1[j])
      {
	  a[k]=l[i];
	  i++;
      }
      else
      {
	  a[k]=r1[j];
	  j++;
      }
   }
}

void mergesort(int a[],int p,int r)
{  int q;
   if(p<r)
   {
      q=(p+r)/2;
      mergesort(a,p,q);
      mergesort(a,q+1,r);
      merge(a,p,q,r);
   }
}

void main()
{
   int a[50],n,i;
   clrscr();
   printf("Enter the size of array-");
   scanf("%d",&n);
   printf("\nEnter the elements of the array-");
   for(i=0;i<n;i++)
	scanf("%d",&a[i]);
   mergesort(a,0,n-1);
   printf("\n array after sorting-");
   for(i=0;i<n;i++)
     printf("%d",a[i]);
   getch();
}