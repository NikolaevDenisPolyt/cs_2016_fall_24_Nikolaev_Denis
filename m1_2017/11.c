#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int opoc(char *a)

{setlocale(LC_CTYPE, "Russian");
int j,dec=0,i;
j=strlen(a)-1;
for(i=0;a[i]!='\0';++i)
{
if(a[i]=='1')
dec=dec+pow(2,j);
j--;
}
return dec;
}
int main() {
  setlocale(LC_CTYPE, "Russian");
char N[1000];
printf("Введите двоичное число:");
gets(N);
printf("%d\n",opoc(N));
return 0;
}
