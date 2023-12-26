#include "header.h"

int main(void)
{
    system("chcp 1251");
    library_t* libraries_database;
    int size = 0;
    libraries_database = (library_t*)malloc(size * sizeof(library_t));
    size = load(&libraries_database,size);
    sort_libraryNumber(libraries_database, size);

    for (;;)
    {
		int number;

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
			libraries_database = new_library(libraries_database, &size);
			break;
		case 2:
			sort_libraryNumber(libraries_database, size);
			libraries_database = delete_library(libraries_database, &size);
			break;
		case 3:
			libraries_database = edit_library(libraries_database);
			break;
		case 4:
			libraries_database = show_all(libraries_database, size);
			break;
		case 5:
			libraries_database = search(libraries_database, size);
			break;
		case 6:
			libraries_database = sort(libraries_database, size);
			break;
		case 7:
			save(libraries_database, size);
			break;
		default:
			break;
		}
    }
    return 0;
}

