#include <stdio.h>
#include <locale.h>
int main()
{setlocale(LC_CTYPE, "Russian");
    int day, mounth, change;
    printf("Введите день вашего рождения:");
    scanf("%i", &day);
    printf("Введите месяц вашего рождения):");
    scanf("%i", &mounth);
    change = mounth;
    mounth = day;
    day = change;
    printf("%i.%i\n", day, mounth);
    return 0;
}
