#include <stdio.h>
#include <string.h>
#include <locale.h>
int main()
{setlocale(LC_CTYPE, "Russian");
int i,j=0;
char c[1000],b[1000];
gets(c);
b[0]=c[0];
for(i=0;c[i]!='\0';i++)
{ if(b[j-1]!=c[i]){
 b[j]=c[i];
printf("%c",b[j]);
j++;
}
}
return 0;
}
