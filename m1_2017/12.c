#include <stdio.h>
#include <string.h>
#include <locale.h>
int main()
{setlocale(LC_CTYPE, "Russian");
    char c,a[100];
    int as[100],i=0,max;
    max=as[0];
    printf("Введите строку:\n");
    gets(a);
    int l=strlen(a);
    for (i=0;i<l;++i){
        as[i]=(int)a[i];
        if (max<as[i])
            max=as[i];
    }
    printf("Наибольший ASCII код - %c\n", (char)max);
    return 0;
}
