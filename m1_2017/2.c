#include <stdio.h>
#include <locale.h>
int main()
{setlocale(LC_CTYPE, "Russian");
    int day, mounth, change;
    printf("Введите день и месяц вашего рождения(xx.xx):");
    scanf("%i.%i", &day, &mounth);
    change = mounth;
    mounth = day;
    day = change;
    printf("%i.%i\n", day, mounth);
    return 0;
}
