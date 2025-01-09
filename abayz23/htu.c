#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;


void initlist(List* head)
{
    *head = NULL;
}

bool isempty(List* head)
{
    return *head == NULL;
}

void insertback(List* head, int val)
{
    List new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = val;
    new_item->next = NULL;

    if (isempty(head))
    {
        *head = new_item;
    }
    else
    {
        List temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_item;
    }
}
int length(List* head)
{
    int count = 0;
    List current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void destroyitem(List* head) {
    if (isempty(head))
    {
        return NULL;
    }
    List temp = *head;
    *head = (*head)->next;
    free(temp);
}

void destroyite(List* head) {
    if (isempty(head))
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    List temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void printList(List head) {
    List temp = head;
    while (temp != NULL) {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

List getitem(List* head, int val) //Ищет и возвращает узел с одинаковым полем number
{
    List cursor = *head;
    while (cursor != NULL)
    {
        if (cursor->number == val)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}
List getitems(List* head, char* str) //Ищет и возвращает узел с одинаковым полем name
{
    List cursor = *head;
    while (cursor != NULL)
    {
        if (strcmp(cursor->name, str) == 0)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

int main() 
{
    setlocale(LC_CTYPE,"RUS");
    List myList;
    initlist(&myList);

    for (int i = 1; i <= 11; i++) 
    {
        insertback(&myList, i);
    }

    printf("До удаления: ");
    printList(myList);

    destroyitem(&myList);
    destroyite(&myList);

    printf("После удаления: ");
    printList(myList);

    return 0;
}
