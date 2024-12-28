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

void initlist(List*); /* ������������� ������ ������ ���������� */
void insertfront(List*, int val); /* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertback(List*, int val); /* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertfront(List*, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
void insertback(List*, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
bool isempty(List*)/* ���������, �������� �� ������ ������*/
int length(List); /* ����������� ����� ������ */
void destroyItem(List*, List node); /* �������� ��������� ���� node �� ������ */
Listitem getitem(List, int n); /* ���������� ���� �� ��������� n � ���� number*/
Listitem getitem(List, char* str); /* ���������� ���� �� ��������� str � ���� name*/
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
		printf("������ ��������� ������.");
		return head;
	}
	else printf("������ ��������.");
	head = heado;
	for (int i = SIZE - 1; i > index; i--)
	{
		head[i] = head[i - 1];
	}
	head = val;
	SIZE = size;

	printf("\n�������� ������� %s\n", head);
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
		printf("������ ��������� ������.");
		return head;
	}
	else printf("������ ��������.");
	head = heado;
	for (int i = SIZE - 1; i > index; i--)
	{
		head[i] = head[i - 1];
	}
	if (strcmp(head,str)>0)
	head = str;
	SIZE = size;

	printf("\n�������� ������� %s\n", head);
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