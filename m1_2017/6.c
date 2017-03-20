#include <stdio.h>
#include <locale.h>


int main()
{
    setlocale(LC_CTYPE, "Russian");
    int num,res,n;
    printf("Введите число : ");
    scanf("%i", &n);
    res = 1;
    for (num = 1; num <= n;num++)
    res *= (num);
    printf("%i", res);
    return 0;

}
