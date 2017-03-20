#include <stdio.h>
#include <string.h>
char reverse( char *c)
{
int j=0,i,m;
char mas1[1000];
m=strlen(c);
for(i=m-1;i>=0;--i)
{
mas1[j]=c[i];
j++;
}
for(i=0;c[i]!='\0';++i)
{
c[i]=mas1[i];
}
return *c;
}
int main()
{
int i;
char mas1[1000];
gets(mas1);
reverse(mas1);
for( i=0;mas1[i]!='\0';++i)
{
printf("%c",mas1[i]);
}
return 0;
}
