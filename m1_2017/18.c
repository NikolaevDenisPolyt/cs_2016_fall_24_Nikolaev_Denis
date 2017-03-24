#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void copy(char *c,char *x)
{ char str[1000];
FILE *C,*X;

C=fopen(c,"r");
X=fopen(x,"w");
char i;
while((i=fgetc(C))!=EOF)
{
fputc(i,X);
}
}

int main()
{setlocale(LC_CTYPE, "Russian");
char a[1000],b[1000];
printf("Введите путь к расположению файла который копируют(C:\/Games\/filename1.txt)");
gets(a);
printf("Введите расположение файла куда копировать (C:\/Games\/filename2.txt)");
gets(b);
copy(a,b);
printf("Сделано");
return 0;
}
