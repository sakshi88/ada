#include<stdio.h>
#include<conio.h>

void naive(int pat[30],int text[30])
{
    int m,n,s,i,flag;
    m=strlen(pat);
    n=strlen(text);
    for(s=0;s<m-n;s++)
    {
      for(i=0;i<=m;i++)
      {
	if(pat[i]==text[s+i])
	{
	  flag=1;
	}
	else
	{ flag=0;
	}
      }
      if(flag==1)
	printf("shift=%d valid shift\n",s);
      else
	printf("shift=%d invalid shift\n",s);
   }
}

int main()
{
    int pat[30],text[30];
    clrscr();
    printf("Enter the pattern-");
    scanf("%s",pat);
    printf("Enter the text-");
    scanf("%s",text);
    naive(pat,text);
    getch();
}