#include<stdio.h>
#include<conio.h>
#include<string.h>

#define d 256
void check(char pat[30],char text[30],int q)
{
    int m=0,n=0,p=0,t=0,i=0,s=0,h;
    m=strlen(pat);
    n=strlen(text);
    p=0;
    t=0;
    h=1;
    for(i=0;i<m-1;i++)
      h=(h*d)%q;
    for(i=0;i<m;i++)
    {
       p=(d*p+pat[i])%q;
       t=(d*t+text[i])%q;
    }
    for(s=0;s<=n-m;s++)
    {
       if(p==t)
       {
	  for(i=0;i<m;i++)
	  {
	    if(pat[i]!=text[s+i])
	      //printf("pattern found at position%d",s);
	      break;
	    /*else
	    {  printf("spurious shift");
	       break;
	    } */
	  }
       if(i==m)
	 printf("valid shift pattern found at %d index",s);
       }

       if(s<n-m)
	{  t=(d*(t-text[s]*h)+text[s+m])%q;
		if(t<0)
		t=t+q;
	}
    }
}

int main()
{
    char pat[20],text[20];
    int q=101;
    clrscr();
    printf("Enter pattern-");
    scanf("%s",pat);
    printf("Enter text-");
    scanf("%s",text);
    check(pat,text,q);
    getch();
    return 0;
}