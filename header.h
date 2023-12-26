#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

/*
* ������������ ������������ �����
*/

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

/*
* ��������� library_t ������ ���������� � ����������
* number - ����� ���������� � ���� ������
* name - ��� ����������
* description - �������� ����������
* language - ���� ���������������� ��� �������� ������� ����������
* version - ������ ����������
* author - ����� ����������
* license - �������� ����������
*/
typedef struct {
	int number; 
	char name[51]; 
	char description[201];
	char language[51];
	float version; 
	char author[51]; 
	char license[51]; 
}library_t;
/*
* ������� new_library - ��������� ����� ���������� � ���� ������
* �������� ����� ��������� ����������� �������������
* ������ ��� ����� ��������� ���������� � ���� ������
* ������� ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* ptr_size - ��������� �� ������ ���� ������
*/
library_t* new_library(library_t*, int*);
/*
* ������� choice_num - ���������� ����� �������� �������������
*/
int choice_num(void);
/*
* ������� delete_library - ������� ���������� �� ���� ������
* ��������� ������ ���� ���������, ������������� ����� ��������, �� 1
* ������, ������� ���� �������� ��� �������� ����������, �������������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* delete_library(library_t*,int*);
/*
* ������� edit_library - ��� ����������� �������� ���������� � ����������, ��������� �������������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
*/
library_t* edit_library(library_t*);
/*
* ������� show_library - ������� ���������� �� ��������� ���������� � �������
* ptr_arr - ��������� �� ������ ��������
* index - ������ ����������
*/
void show_library(library_t*,int);
/*
* ������� show_all - ������� ��� ���������� �� ���� ������ � �������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* show_all(library_t*,int);
/*
* ������� put_term - ���������� �������� ������� ������
*/
char* put_term(void);
/*
* ������� search - ���������� � ������� ������, ������� ������ ������������, ����������� ����� �����
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* search(library_t*, int);
/*
* ������� search_libraryLanguage - ��������� ����� ��������� ��������������� �������� ������������� ����� ����������������
* ������� ��������� ���������� � �������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* search_libraryLanguage(library_t*,int);
/*
* ������� search_libraryName - ��������� ����� ��������� ��������������� �������� ������������� �������� ����������
* ������� ��������� ���������� � �������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* search_libraryName(library_t*,int);
/*
* ������� sort - ���������� � ������� ����������, ������� ������ ������������, ����������� ����� �����
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* sort(library_t*, int);
/*
* ������� sort_libraryVersion - ��������� ���������� �� ������� ���������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* sort_libraryVersion(library_t*,int);
/*
* ������� sort_libraryNumber - ��������� ���������� �� ������� ��������� � ���� ������
* ���������� ��������� �� ������ ��������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
library_t* sort_libraryNumber(library_t*, int);
/*
* ������� compare - ���������� �������, ������������ ��� ����������
* ��������� ���������
*/
void compare(void*, void*);
/*
* ������� init_list - �������������� ������
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
void init_list(library_t*, int);
/*
* ������� save - ��������� ���� ������ � ����
* ptr_arr - ��������� �� ������ ��������
* size - ������ ���� ������
*/
int save(library_t*,int);
/*
* ������� load - ������ ������ ���� ������ � ���� ������ �� �����
* pp_arr - ��������� �� ��������� �� ������ ��������
* size - ������ ���� ������
*/
int load(library_t**,int);
