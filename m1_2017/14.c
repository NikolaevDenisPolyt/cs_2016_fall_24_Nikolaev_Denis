#include <stdio.h>
#include <string.h>
#include <locale.h>
int main()
{setlocale(LC_CTYPE, "Russian");
int i,j,b[1000];
char c[1000];
gets(c);
i=strlen(c);
for(i=i-1;i!=-1;i--)
{
printf("%c",c[i]);

}

return 0;
}
