#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <Windows.h>
#ifndef _LIST_H
#define _LIST_H

struct listitem {
	int number;
	char name[80];
	struct listitem* next;
};

typedef struct listitem* List;

void initlist(List*); /* инициализация списка пустым содержимым */
void insertfront(List*, int val); /* вставка в список перед узлом со значением поля number=val */
void insertback(List*, int val); /* вставка в список перед узлом со значением поля number=val */
void insertfront(List*, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertback(List*, char* str); /* вставка в список перед узлом со значением str в поле name */
bool isempty(List*)/* проверяет, является ли список пустым*/
int length(List); /* определение длины списка */
void destroyItem(List*, List node); /* удаление заданного узла node из списка */
Listitem getitem(List, int n); /* нахождение узла со значением n в поле number*/
Listitem getitem(List, char* str); /* нахождение узла со значением str в поле name*/
#endif /* _LIST_H */


int mine()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "RUS");
	int SIZE;
	scanf_s("%d", &SIZE);
	List head = (List)malloc(SIZE * sizeof(struct listitem));
	if (head == NULL)
	{
		printf("Error, couldn't allocate memory.");
		return 0;
	}
	else
	{
		printf("Memoty allocate.");
	}

}


void initlist(List* head, int SIZE)
{
	List head = (List)calloc(SIZE, sizeof(struct listitem));
	if (head == NULL)
	{
		printf("Error, couldn't allocate memory.");
		return 0;
	}
	else
	{
		printf("Memoty allocate.");
	}
	return head;
}


void insertfront(List* head, int SIZE, int val)
{
	int size = (SIZE)+1;
	List heado = (List)realloc(head, sizeof(struct listitem));
	if (heado == NULL)
	{
		printf("Ошибка выделения памяти.");
		return head;
	}
	else printf("Память выделена.");
	head = heado;
	for (int i = SIZE - 1; i > index; i--)
	{
		head[i] = head[i - 1];
	}
	head = val;
	SIZE = size;

	printf("\nДобавлен продукт %s\n", head);
	return head;
}


void insertback(List* head, int val)
{

}


void insertfront(List* head, int SIZE, char* str)
{
	int size = (SIZE)+1;
	List* heado = (List*)realloc(head, size * sizeof(List));
	if (heado == NULL)
	{
		printf("Ошибка выделения памяти.");
		return head;
	}
	else printf("Память выделена.");
	head = heado;
	for (int i = SIZE - 1; i > index; i--)
	{
		head[i] = head[i - 1];
	}
	if (strcmp(head,str)>0)
	head = str;
	SIZE = size;

	printf("\nДобавлен продукт %s\n", head);
	return head;
}


void insertback(List* listik, char* str)
{

}


bool isempty(List* listik)
{

}


int length(List listik);


void destroyItem(List* listik, List node);


listitem getitem(List listik, int n)
{

}


Listitem getitem(List listik, char* str)
{

}