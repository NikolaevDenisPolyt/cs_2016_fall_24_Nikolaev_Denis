#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a=0,c=0,d=0,m=0,k=0;
    char b=0 ;
    int i=0;
    scanf("%f%c%f",&a, &b,&c);
    if(b=='-')
    {
       m=a-c;
    }
    else if(b=='+')
    {
        m=a+c;
    }
      else if(b=='*')
    {
        m=a*c;
    }
      else if(b=='/')
    {
        m=a/c;
    }
      else if(b=='%')
    {
        m=(int)a%(int)c;
    }
      else if(b=='^')
        m=1;
    {
        for(i=0;i<c;i++)

            m*=a;
    }
    printf("%.3f%c%.3f=%.3f",a,b,c,m);
    return 0;
}
