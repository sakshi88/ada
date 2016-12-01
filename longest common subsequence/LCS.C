#include<stdio.h>
#include<conio.h>
#include<string.h>

char x[20],y[20],b[20][20];
int i,j,m,n,c[20][20];

void lcs()
{
   m=strlen(x);
   n=strlen(y);
   for(i=0;i<=m;i++)
     c[i][0]=0;
   for(i=0;i<=n;i++)
     c[0][i]=0;
   for(i=0;i<=m;i++)
   {
      for(j=0;j<=n;j++)
      {
	  if(x[i-1]==y[i-1])
	  {
	    c[i][j]=c[i-1][j-1]+1;
	    b[i][j]='a';
	  }
	  else if(c[i-1][j]<=c[i][j-1])
	  {
	     c[i][j]=c[i][j-1];
	     b[i][j]='b';
	  }
	  else
	  {
	     c[i][j]=c[i-1][j];
	     b[i][j]='c';
	  }
     }
  }
}

void print(int i,int j)
{
	if(i==0||j==0)
		return;
  if(b[i][j]=='a')
  {
      print(i-1,j-1);
      printf("%c",x[i-1]);
  }
  else if(b[i][j]=='b')
    print(i,j-1);
  else
    print(i-1,j);
}

void main()
{
    clrscr();
    printf("Enter 1st sequence");
    scanf("%s",x);
    printf("\nEnter 2nd sequence-");
    scanf("%s",y);
	printf("Longest common subsequence is-");
    lcs();
    print(m,n);
    getch();
}