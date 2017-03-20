#include <stdio.h>
#include <locale.h>


int main()
{
    setlocale(LC_CTYPE, "Russian");
    float m1, f, v4;
    printf("Введите нижнюю границу интервала : ");
    scanf("%f", &v4);
    printf("Введите верхнюю границу интервала : ");
    scanf("%f", &m1);
    printf("      C      |      F      \n"
           "_____________|_____________\n");
    if (v4 <=m1)
    {
         while (v4 <= m1)
       {

           f = 1.8*v4+32;
           printf("%12f | %12f\n", v4, f);
           v4 += 1;
        }
    }
    else
    {
      printf("Введите правилюльную границу интервала ");
    }

    return 0;
}
