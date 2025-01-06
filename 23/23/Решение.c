#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#ifndef _LIST_H
#define _LIST_H

struct listitem {
	int number;
	char name[80];
	struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* head, int SIZE); /* инициализация списка пустым содержимым */
void insertfront(List* head, List* next, int SIZE, int val); /* вставка в список перед узлом со значением поля number=val */
void insertback(List* head, List* next, int SIZE, int val); /* вставка в список после узлом со значением поля number=val */
void insertfrontе(List* head, int SIZE, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertbackе(List* head, char* str); /* вставка в список после узлом со значением str в поле name */
bool isempty(List* head);/* проверяет, является ли список пустым*/
int length(List head);/* определение длины списка */
void destroyItem(List* head, List node, int SIZE); /* удаление заданного узла node из списка */
List getitem(List* head, int n, int data); /* нахождение узла со значением n в поле number*/
List getitems(List* head, int SIZE, char* str); /* нахождение узла со значением str в поле name*/
#endif /* _LIST_H */


int mine()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "RUS");
	int SIZE;
	scanf_s("%d", &SIZE);
	List head = (List)malloc(SIZE * sizeof(struct listitem));
	List next = (List)malloc(SIZE * sizeof(struct listitem));
	if (head == NULL)
	{
		printf("Error, couldn't allocate memory.");
		return 0;
	}
	else
	{
		printf("Memoty allocate.");
	}
	int c;
	printf("\n\t\tМеню.\n\t\t1.Инцилизация списка пустым значением.");
	printf("\n\t\t2.Проверка является ли список пустым.");
	printf("\n\t\t3.Определение длины списка");
	printf("\n\t\t4.");
	printf("\n\t\t5.");
	printf("\n\t\t6.");
	printf("\n\t\t7.");
	printf("\n\t\t0.Выход\n");
	printf("\nВыберете желаемую операцию > ");
	scanf_s("%d", &c);
	switch (c)
	{
	case 1:
	{
		printf("Инцилизация пустым значением");
		initlist(head, SIZE);
		break;
	}
	case 2:
	{
		isempty(head);
		break;
	}
	case 3:
	{
		length(head);
		break;
	}
	default:
		printf("Не верно введено зн-е.");
		break;
	}
}

void putslist(List head)
{
	List p = head;
	int k = 0;
	while (p != NULL) {
		printf("узел %d данные: %s, %d адрес следующего узла %p\n",

			k++, p->number, p->name, p->next);

		p = p->next;
	}
}

void initlist(List* head, int SIZE)
{
	List h = (List)calloc(SIZE, sizeof(struct listitem));
	if (h != NULL)
	{
		h->number = 0;
		memset(h->name, 0, sizeof(h->name));
		h->next = NULL;
	}
	return h;
}


void insertfront(List* head, List* next, int SIZE, int val)
{
	
	if (next == NULL || head == NULL)
		return NULL;
	if (head == next)
	{
		head = prepend(head, val);
		return head;
	}
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->next == next)
			break;
		cursor = cursor->next;
	}
	if (cursor != NULL)
	{
		List* new_node = create(val, cursor->next);
		cursor->next = new_node;
		return head;
	}
	else
	{
		return NULL;
	}
}


void insertback(List* head, List* next, int SIZE, int val)
{
	
	if (next == NULL || head == NULL)
		return NULL;
	if (head == next)
	{
		head = prepend(head, val);
		return head;
	}
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->number == val)
			break;
		cursor = cursor->next;
	}
	if (cursor != NULL)
	{
		int new_val = val++;
		List* new_node = create(new_val, cursor->next);
		cursor->next = new_node;
		return head;
	}
	else
	{
		return NULL;
	}
}


void insertfrontе(List* head, int SIZE, char* str)
{
	
}


void insertbackе(List* head, char* str)
{

}


bool isempty(List* head)
{
	if (head != NULL)
	{
		printf("List != NULL");
		return head;
	}
	else
	{
		printf("List == NULL");
		return 0;
	}
}


int length(List head)
{
	for (;;);
}


void destroyItem(List* head, List node, int SIZE)
{
	/* if the node is the first node */
	if (node == *head)
	{
		*head = remove_front(*head);
		return head;
	}
	/* if the node is the last node */
	if (node->next == NULL)
	{
		*head = remove_back(*head);
		return head;
	}
	/* if the node is in the middle */
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->next = head)
			break;
		cursor = cursor->next;
	}
	if (cursor != NULL)
	{
		List tmp = cursor->next;
		cursor->next = tmp->next;
		free(tmp);
	}
	return head;
}


List getitem(List* head, int SIZE, int data)
{
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->number == data)
			return cursor;
		cursor = cursor->next;
	}
	return NULL;
}


List getitems(List* head, int SIZE, char* str)
{
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->number == str)
			return cursor;
		cursor = cursor->next;
	}
	return NULL;
}