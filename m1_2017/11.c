#include <stdio.h>
#include <math.h>
#include <string.h>
int r(char *a)
{
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
char N[1000];
printf("Введите двоичное число ");
gets(N);
printf("%d\n",r(N));
return 0;
}
