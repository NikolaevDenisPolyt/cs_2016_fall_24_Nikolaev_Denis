#include <stdio.h>
#include <string.h>
#include <locale.h>
int main()
{setlocale(LC_CTYPE, "Russian");
int i,b[1000];
char c[1000];
gets(c);
for(i=0;c[i]!='\0';i++)
{
b[i]=c[i];

}
char max1 = b[0];
for(i;i>=0;i--)
{
  if (b[i]>max1)
      max1=b[i];
}
printf("Наибольший ASCII код:%i\n",max1);
printf("\n\n");
return 0;
}
