#include <stdio.h>
#include <math.h>
#include <locale.h>
float mainFunction(float x) {
	float function;
	function = x*x;
	return function;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	float h, x, a, b;
	float P = 0;
	float P1 = 0;
	float P2 = 0;

	 char znak;
	 printf(" The following is an example of differentiating  function   Y=X^2 from three points.\n"
         "If you want to change a function, change the parameters in the code \n");
	printf(" Enter accuracy of the value(Max:9): ");
	scanf("%c", &znak);
	char string[] = "%.zf\n";
	string[2] = znak;
	printf("Lower bound of the interval: ");
	scanf("%f", &a);
	printf("Upper bound of  the interval: ");
	scanf("%f", &b);
	printf("Enter your step: ");
	scanf("%f", &h);
	x = a;
	P1 = (1 / (2 * h))*((-3) * mainFunction(x) + 4 * (mainFunction(x + h)) - (mainFunction(x + 2 * h)));
	P2 = (1 / (2 * h))*(-mainFunction(x) + mainFunction(x + 2 * h));
	printf(string, P1);
	printf(string, P2);
	while (x + 2 * h <= b) {
		P = (1 / (2 * h))*(mainFunction(x) - 4 * (mainFunction(x + h)) + 3 * (mainFunction(x + 2 * h)));
		x = x + h;
		printf(string, P);
	}
	return 0;
}
