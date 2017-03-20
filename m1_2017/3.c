#include <stdio.h>
#include <locale.h>
int main() {

    setlocale(LC_CTYPE, "Russian");
	float x,y,a,b,c,d;
	printf("Введите числа в формате a+bi,x+yi\n ");
	scanf("%f+%fi,%f+%fi", &x, &y, &a, &b);
	c = (x*x*a+x*a*a+x*b*b+a*y*y)/((x+a)*(x+a)+(y+b)*(y+b));
	d = (x*x*b+a*a*y+y*y*b+y*b*b)/((x+a)*(x+a)+(y+b)*(y+b));
	printf("(%.3f)+(%.3fi)", c, d);
	return 0;
}
