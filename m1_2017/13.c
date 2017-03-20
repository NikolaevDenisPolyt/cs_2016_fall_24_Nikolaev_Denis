#include <stdio.h>
#include <string.h>

int main()
{
int m,i,b[1000],j=0,k=0,x;
char c[1000];
gets(c);
m=-1;
for(i=0;c[i]!='\0';i++)
{
if(c[i]==' ')
{if(j==0)
{b[j]=i;
j++;
k=i;
m=0;
}else {
b[j]=i-1-k;
j++;
k=i;
}
}
else
if(c[i+1]=='\0')
{
b[j]=i-k-m;
j++;
}
}
for(i=0;i<j;i++)
{
for( x=0;x<b[i];x++)
printf("=");
printf("\n\n");
}
return 0;
}
