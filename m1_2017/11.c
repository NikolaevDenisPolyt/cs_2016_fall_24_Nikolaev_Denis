#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int opoc(char *a)

{setlocale(LC_CTYPE, "Russian");
int j,s=0,i;
j=strlen(a)-1;
for(i=0;a[i]!='\0';++i)
{
if(a[i]=='1')
s=s+pow(2,j);
j--;
}
return s;
}
int main() {
  setlocale(LC_CTYPE, "Russian");
char N[1000];
printf("Введите двоичное число:");
gets(N);
printf("%d\n",opoc(N));
return 0;
}
