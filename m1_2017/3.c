#include <stdio.h>
#include <locale.h>
int main() {

    setlocale(LC_CTYPE, "Russian");
	float x,y,a,b,c,d;
	printf("Введите числа в СТАНДАРТНОЙ ФОРМЕ.При наличии отрицательного мнимого элемента вводить:a+-bi\n ");
	printf("Введите число в формате a+bi\n ");
	scanf("%f+%fi", &x, &y);
	printf("Введите число в формате a+bi\n ");
	scanf("%f+%fi", &a, &b);
	c = (x*x*a+x*a*a+x*b*b+a*y*y)/((x+a)*(x+a)+(y+b)*(y+b));
	d = (x*x*b+a*a*y+y*y*b+y*b*b)/((x+a)*(x+a)+(y+b)*(y+b));
	printf("(%.3f)+(%.3fi)", c, d);
	return 0;
}

