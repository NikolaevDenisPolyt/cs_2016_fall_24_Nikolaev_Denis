#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{    setlocale(LC_CTYPE, "Russian");
    float x,x1,x2 = 0.0;
    float a,b,c = 0.0;
    printf("Введите коэффициенты a b c(через пробел)\n");
    scanf("%f %f %f",&a,&b,&c);
    float d = b*b-4*a*c;
    float d1 = sqrtf(d);
    if (d>=0)
    {
     if (d==0)
            {
            x = (-b+d1)/(2*a);
            printf("x=%.3f\n", x);
            }
     else{
            x1 = (-b+d1)/(2*a);
            x2 = (-b-d1)/(2*a);
            printf("x1=%.3f, x2=%.3f\n", x1, x2);
        }
    }
    else{
        printf("Нет вещественных корней \n");
    }
    return 0;
}
