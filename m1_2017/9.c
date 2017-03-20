#include <stdio.h>
#include <locale.h>
int fib(int x1)
{
    if (x1==0||x1==1)
    {
        return x1;
    }
    else
    {
        return fib(x1-1)+fib(x1-2);
    }


}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int x1;
    printf("Введите номер : ");
    scanf("%i", &x1);
    printf("%i:число Фибоначчи номер %i" , fib(x1),x1);
    return 0;

}
