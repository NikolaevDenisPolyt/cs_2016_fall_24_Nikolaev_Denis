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
b[i]=c[i];
printf("%i,",b[i]);
}
char max1 = b[0];
for(i;i>=0;i--)
{
  if (b[i]>max1)
      max1=b[i];
}
printf("%i\n",max1);
printf("\n\n");
return 0;
}
