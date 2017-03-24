#include <stdio.h>
#include <locale.h>


int main()

	{setlocale(LC_CTYPE, "Russian");
	char file1[255], key[100];
	int i;
	FILE*f1;
	FILE*f2;
	int fsize = 0, dsize = 0;
	char * wa1;
	for (i = 0; i < 255; i++)
		file1[i] = '\0';
	for (i = 0; i < 100; i++)
		key[i] = '\0';
	printf("Введите ключ: ");
	gets(key);
	printf("Путь к  файлу (Например: C:\/Papka\/file.xls): ");
	gets(file1);
	for (i = 0; ;i++)
	{
		if (key[i] == '\0') break;
		dsize++;
	}
	f1 = fopen(file1, "rb");
	fseek(f1, 0, SEEK_END);
	fsize = ftell(f1);
	rewind(f1);
	wa1 = (char *)malloc(fsize);
	fread(wa1, 1, fsize, f1);
	fclose(f1);
	int index = 0;
	for (i = 0; i < fsize; i++)
	{
		if (index == dsize) index = 0;
		wa1[i] ^= key[index];
		index++;
	}
	f2 = fopen(file1, "w");

	fwrite(wa1, 1, fsize, f2);

	fclose(f2);
	free(wa1);
	printf("Операция шифрования/дешифрования выполнена");
	return 0;
}
