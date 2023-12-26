#include "header.h"

library_t* new_library(library_t *ptr_arr,int* ptr_size)
{

	library_t library;
	int sz = *ptr_size;

	printf("Введите название библиотеки: ");
	gets(library.name);

	printf("Введите описание библиотеки: ");
	gets(library.description);

	printf("Введите язык программирования: ");
	gets(library.language);

	printf("Введите версию библиотеки: ");
	scanf("%f", &library.version);
	getchar();

	printf("Введите автора библиотеки: ");
	gets(library.author);

	printf("Введите лицензию библиотеки: ");
	gets(library.license);


	sz++;
	library.number = sz;
	ptr_arr = (library_t*)realloc(ptr_arr, sz * sizeof(library_t));
	ptr_arr[library.number - 1] = library;
	*ptr_size = sz;
	puts("\nБиблиотека успешно добавлена");
	return ptr_arr;
}

int choice_num(void)
{
	int x;
	scanf("%d", &x);
	return x;
}

library_t* delete_library(library_t* ptr_arr, int* ptr_size)
{
	int library_number;
	int newsize = *ptr_size;
	puts("\nВведите номер библиотеки:");
	library_number = choice_num();

	if (library_number > *ptr_size)
		puts("Введён неверный номер библиотеки");
	else
	{
		for (int i = library_number - 1; i < *ptr_size - 1; i++) {
			ptr_arr[i] = ptr_arr[i + 1];
			ptr_arr[i].number--;
		}
		newsize--;
		*ptr_size = newsize;

		if (newsize == 0)
			ptr_arr = (library_t*)malloc(newsize * sizeof(library_t));
		else
			ptr_arr = (library_t*)realloc(ptr_arr, newsize * sizeof(library_t));

		puts("\nБиблиотека успешно удалена");
	}

	return ptr_arr;
}

library_t* edit_library(library_t* ptr_arr)
{
	int library_number;
	int num;
	puts("Введите номер библиотеки:");
	library_number = choice_num();

	puts("Что хотите изменить?");
	puts("[1 - Название библиотеки]");
	puts("[2 - Описание библиотеки]");
	puts("[3 - Язык программирования]");
	puts("[4 - Версию]");
	puts("[5 - Автора]");
	puts("[6 - Лицензию]");
	puts("[7 - Всё]");

	num = choice_num();
	getchar();

	switch (num) {
	case 1:
		printf("Введите название библиотеки: ");
		gets(ptr_arr[library_number-1].name);
		break;
	case 2:
		printf("Введите описание библиотеки: ");
		gets(ptr_arr[library_number-1].description);
		break;
	case 3:
		printf("Введите язык программирования: ");
		gets(ptr_arr[library_number-1].language);
		break;
	case 4:
		printf("Введите версию библиотеки: ");
		scanf("%f", &ptr_arr[library_number-1].version);
		getchar();
		break;
	case 5:
		printf("Введите автора библиотеки: ");
		gets(ptr_arr[library_number-1].author);
		break;
	case 6:
		printf("Введите лицензию библиотеки: ");
		gets(ptr_arr[library_number-1].license);
		break;
	case 7:
		printf("Введите название библиотеки: ");
		gets(ptr_arr[library_number -1].name);

		printf("Введите описание библиотеки: ");
		gets(ptr_arr[library_number - 1].description);

		printf("Введите язык программирования: ");
		gets(ptr_arr[library_number - 1].language);
		
		printf("Введите версию библиотеки: ");
		scanf("%f", &ptr_arr[library_number - 1].version);
		getchar();

		printf("Введите автора библиотеки: ");
		gets(ptr_arr[library_number - 1].author);

		printf("Введите лицензию библиотеки: ");
		gets(ptr_arr[library_number-1].license);

		break;
	}
	puts("\nИнформация успешно изменена");
	return ptr_arr;
}

void show_library(library_t* ptr_arr,int index)
{
	printf("| %16d ", ptr_arr[index].number);
	printf("| %20s", ptr_arr[index].name);
	printf("| %30s", ptr_arr[index].description);
	printf("| %22s", ptr_arr[index].language);
	printf("| %9.2f", ptr_arr[index].version);
	printf("| %18s", ptr_arr[index].author);
	printf("| %17s |\n", ptr_arr[index].license);
}

library_t* show_all(library_t* ptr_arr, int size)
{
	printf("\n| %16s | %15s | %29s | %15s |  %4s  |  %15s  |  %15s  |\n", "Номер библиотеки", "Название библиотеки", "Описание библиотеки     ", "Язык программирования", "Версия", "Автор     ", "Лицензия   ");
	for (int i = 0; i < size; i++)
		show_library(ptr_arr, i);
	return ptr_arr;
}

//search

char* put_term(void)
{
	char* term[51];
	printf("Введите признак: ");
	gets(term);
	return term;
}

library_t* search(library_t* ptr_arr, int size)
{
	int searchNumber;

	puts("\nВыберите признак поиска");
	puts("[1 - по языку программирования]");
	puts("[2 - по названию библиотеки]");

	searchNumber = choice_num();
	switch (searchNumber){
		case 1:
			ptr_arr = search_libraryLanguage(ptr_arr, size);
			break;
		case 2:
			ptr_arr = search_libraryName(ptr_arr, size);
			break;
		default:
			return ptr_arr;
			break;
	}
	return ptr_arr;
}

library_t* search_libraryLanguage(library_t* ptr_arr, int size)
{
	getchar();
	char  *term = put_term();
	char str[200];
	char str_arr[7][50] = { "Номер библиотеки", "Название библиотеки", "Описание библиотеки     ", "Язык программирования", "Версия", "Автор     ", "Лицензия   " };
	sprintf(str, "\n| %16s | %15s | %29s | %15s |  %4s  |  %15s  |  %15s  |", str_arr[0], str_arr[1], str_arr[2], str_arr[3], str_arr[4], str_arr[5], str_arr[6]);
	puts(str);
	for (int i = 0; i < size; i++)
		if (strcmp(term, ptr_arr[i].language) == 0)
			show_library(ptr_arr, i);
	
	return ptr_arr;
}
library_t* search_libraryName(library_t* ptr_arr, int size)
{
	getchar();
	char* term = put_term();
	char str[200];
	char arr[7][50] = { "Номер библиотеки", "Название библиотеки", "Описание библиотеки     ", "Язык программирования", "Версия", "Автор     ", "Лицензия   " };
	sprintf(str, "\n| %16s | %15s | %29s | %15s |  %4s  |  %15s  |  %15s  |", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
	puts(str);
	for (int i = 0; i < size; i++)
		if (strcmp(term, ptr_arr[i].name) == 0)
			show_library(ptr_arr, i);

	return ptr_arr;
}

//sort

library_t* sort(library_t* ptr_arr, int size)
{
	int sortNumber;

	puts("Выберите сортировку");
	puts("[1 - по версии]");
	puts("[2 - по номеру]");
	puts("[3 - qsort(по версии)]");

	sortNumber = choice_num();
	switch(sortNumber) {
	case 1:
		sort_libraryVersion(ptr_arr, size);
		break;
	case 2:
		sort_libraryNumber(ptr_arr, size);
		break;
	case 3:
		qsort(ptr_arr, size, sizeof(library_t), compare);
		break;
	default:
		return ptr_arr;
		break;
	}
	puts("\nСортировка прошла успешно");
	return ptr_arr;
}
library_t* sort_libraryVersion(library_t* ptr_arr,int size)
{
	float num;
	library_t temp;
	int j;

	for (int i = 1; i < size; i++) {
		num = ptr_arr[i].version;
		j = i - 1;
		while (j >= 0 && ptr_arr[j].version > num) {
			temp = ptr_arr[j + 1];
			ptr_arr[j + 1] = ptr_arr[j];
			ptr_arr[j] = temp;

			j = j - 1;
		}
	}

	return ptr_arr;
}

library_t* sort_libraryNumber(library_t* ptr_arr, int size)
{
	int num;
	library_t temp;
	int j;

	for (int i = 1; i < size; i++) {
		num = ptr_arr[i].number;
		j = i - 1;
		while (j >= 0 && ptr_arr[j].number > num) {
			temp = ptr_arr[j + 1];
			ptr_arr[j + 1] = ptr_arr[j];
			ptr_arr[j] = temp;

			j = j - 1;
		}
	}

	return ptr_arr;
}
void compare(void* arg1, void* arg2)
{
	library_t* a = arg1;
	library_t* b = arg2;

	if (a->version > b->version)
		return 1;

	if (a->version < b->version)
		return -1;

	return 0;
}

void init_list(library_t* ptr_arr, int size)
{
	int t;

	for (t = 0; t < size; ++t)
	{
		ptr_arr[t].name[0] = '\0';
		ptr_arr[t].description[0] = '\0';
		ptr_arr[t].language[0] = '\0';
		ptr_arr[t].author[0] = '\0';
		ptr_arr[t].license[0] = '\0';
	}
}
int save(library_t* ptr_arr, int size)
{
	FILE* fp;

	if ((fp = fopen("library_list.txt", "wt")) == NULL) {
		puts("Ошибка открытия файла");
		return 0;
	};

	fprintf(fp, "%d\n\n", size);

	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d\n", ptr_arr[i].number);
		fprintf(fp, "%s\n", ptr_arr[i].name);
		fprintf(fp, "%s\n", ptr_arr[i].description);
		fprintf(fp, "%s\n", ptr_arr[i].language);
		fprintf(fp, "%.2f\n", ptr_arr[i].version);
		fprintf(fp, "%s\n", ptr_arr[i].author);
		fprintf(fp, "%s\n\n", ptr_arr[i].license);
	}

	fclose(fp);
	puts("\nБаза данных успешно сохранена");
	return 0;
}
int load(library_t **pp_arr, int size)
{
	FILE* fp;
	if ((fp = fopen("library_list.txt", "rt")) == NULL) {
		puts("Ошибка открытия файла");
		return 0;
	};

	fscanf(fp, "%d\n\n", &size);

	if (size == NULL) {
		puts("В файле отсутсвуют элементы");
		return 0;
	} else {	
		library_t *new_arr = (library_t*)malloc(size * sizeof(library_t));
		init_list(new_arr, size);
		for (int i = 0; i < size; i++){
			fscanf(fp, "%d\n", &new_arr[i].number);

			fgets(new_arr[i].name, sizeof(new_arr[i].name), fp);
			strtok(new_arr[i].name, "\n");

			fgets(new_arr[i].description,sizeof(new_arr[i].description), fp);
			strtok(new_arr[i].description, "\n");

			fgets(new_arr[i].language, sizeof(new_arr[i].language), fp);
			strtok(new_arr[i].language, "\n");

			fscanf(fp, "%f\n", &new_arr[i].version);

			fgets(new_arr[i].author, sizeof(new_arr[i].author), fp);
			strtok(new_arr[i].author, "\n");

			fgets(new_arr[i].license, sizeof(new_arr[i].license), fp);
			strtok(new_arr[i].license, "\n");
		}
		*pp_arr = new_arr;
		fclose(fp);
		puts("База данных успешно загружена");
		return size;
	}
	
}



