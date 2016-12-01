#include<stdio.h>
#include<conio.h>

int start[20],finish[20];
int i,j;
void sort(int finish[20],int m)
{
   int temp;
   for(i=0;i<m;i++)
   {
      for(j=0;j<m-i-1;j++)
      {
	 if(finish[j]>=finish[j+1])
	 {
	    temp=finish[j];
	    finish[j]=finish[j+1];
	    finish[j+1]=temp;
	 }
      }
   }
}

void activity(int start[],int finish[],int m)
{
   i=0;
   printf("A%d",i);
   for(j=1;j<m;j++)
   {
      if(start[j]>=finish[i])
      {
	 printf(",A%d",j);
	 i=j;
      }
   }
}

int main()
{
   int m;
   clrscr();
   printf("Enter size of start matrix-");
   scanf("%d",&m);
   printf("Enter the start times-");
   for(i=0;i<m;i++)
   scanf("%d",&start[i]);
   printf("Enter the finish times-");
   for(i=0;i<m;i++)
   scanf("%d",&finish[i]);
   sort(finish,m);
   activity(start,finish,m);
   getch();
   return 0;
}