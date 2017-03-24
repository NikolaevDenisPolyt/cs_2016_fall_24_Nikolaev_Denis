#include <stdio.h>
#define swap(t,x,y) {t c = a; a = b; b = c;}
int main()
{
    int a, b;
    printf("x = ");
	scanf("%i", &a);
	printf("y = ");
	scanf("%i", &b);
    swap(float,a,y);
    printf("%i %i\n", a ,b);
    return 0;
}
