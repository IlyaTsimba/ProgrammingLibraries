#include "header.h"

int main(void)
{
    system("chcp 1251");
    library_t* libraries_database;
	library_t* arr;
	int arr_size = 0;
    int size = 0;
    libraries_database = (library_t*)malloc(size * sizeof(library_t));
	switch (load(&libraries_database, &size)) {
		case 1:
			puts("В файле отсутсвуют элементы");
			break;
		case 2:
			puts("База данных успешно загружена");
			break;
		default:
			puts("Ошибка открытия файла");
			break;
	}
    sort_libraryNumber(libraries_database, size);

    for (;;)
    {
		int number,num;

		printf("\nКоличество библиотек в базе данных: %d\n", size);
		puts("[1 - Добавить библиотеку]");
		puts("[2 - Удалить библиотеку]");
		puts("[3 - Изменить информацию о библиотеке]");
		puts("[4 - Просмотреть все библиотеки]");
		puts("[5 - Поиск библиотеки]");
		puts("[6 - Отсортировать базу данных]");
		puts("[7 - Сохранить изменения]");
		puts("[0 - Выход из программы]");
		puts("Введите цифру");

		number = choice_num();
		getchar();
		system("cls");

		switch (number) {

		case 0:

			exit(0);
			break;

		case 1:

			if (new_library(&libraries_database, input_library(), &size) == 1)
				puts("\nБиблиотека успешно добавлена");
			else
				puts("\nОшибка при добавлении библиотеки");
			break;

		case 2:

			sort_libraryNumber(libraries_database, size);
			puts("\nВведите номер библиотеки:");
			number = choice_num();
			if (delete_library(libraries_database, &size, number) == 1)
				puts("\nБиблиотека успешно удалена");
			else
				puts("\nОшибка при удалении библиотеки");
			break;

		case 3:

			puts("Введите номер библиотеки:");
			number = choice_num();

			puts("Что хотите изменить?");
			puts("[1 - Название библиотеки]");
			puts("[2 - Описание библиотеки]");
			puts("[3 - Язык программирования]");
			puts("[4 - Версию]");
			puts("[5 - Автора]");
			puts("[6 - Лицензию]");
			puts("[7 - Всё]");
			num = choice_num();

			if(edit_library(libraries_database, number, num) == 0)
				puts("\nИнформация успешно изменена");
			break;

		case 4:

			libraries_database = show_all(libraries_database, size);
			break;

		case 5:

			puts("\nВыберите признак поиска");
			puts("[1 - по языку программирования]");
			puts("[2 - по названию библиотеки]");
			number = choice_num();
			arr = search(libraries_database, size, number,&arr_size);
			show_all(arr, arr_size);
			break;

		case 6:

			puts("Выберите сортировку");
			puts("[1 - по версии]");
			puts("[2 - по номеру]");
			puts("[3 - qsort(по версии)]");
			number = choice_num();
			libraries_database = sort(libraries_database, size,number);
			puts("\nСортировка прошла успешно");
			break;

		case 7:

			if(save(libraries_database, size) == 0)
				puts("Ошибка открытия файла");
			else
				puts("\nБаза данных успешно сохранена");
			break;

		default:
			break;
		}
    }
    return 0;
}

