
#ifndef _LIST_H
#define _LIST_H

struct listitem 
{
	int number;
	char name[80];
	struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* head); /*  */
List insertfront(List* head, int val); /* before  number=val */
void insertback(List* head, int val); /* after number=val */
void insertfrontå(List* head, char* str); /* before str name */
void insertbackå(List* head, char* str); /* after str name */
bool isempty(List* head);/* NULL */
int length(List head);/* len */
void destroyItem(List* head); /* node */
List getitem(List* head, int n, int data); /* n number*/
List getitems(List* head, char* str); /* str name*/


int mine()
{
	List head = (List*)malloc(sizeof(struct listitem));
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
	printf("\n\t\tMenu.\n\t\t1..");
	printf("\n\t\t2..");
	printf("\n\t\t3.");
	printf("\n\t\t4.");
	printf("\n\t\t5.");
	printf("\n\t\t6.");
	printf("\n\t\t7.");
	printf("\n\t\t0.Exit\n");
	printf("\nSelect an operation > ");
	scanf_s("%d", &c);
	switch (c)
	{
	case 1:
	{
		printf("");
		initlist(head);
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
		printf("Wrong number.");
		break;
	}
}

void putslist(List head)
{
	List p = head;
	int k = 0;
	while (p != NULL) {
		printf("Element %d data: %s, %d adress %p\n", k++, p->number, p->name, p->next);
		p = p->next;
	}
	printf("NULL\n");
}

void initlist(List* head)
{
	*head = NULL;
}

// void prepend(List** head, int value)
// {
// 	List new_list=(List)malloc(sizeof(struct listitem));
// 	new_list->number=value;
// 	new_list->name[0]='\0';
// 	new_list->next=*head;
// 	*head=new_list;
//  return new_list;
// }

List insertfront(List* head, int SIZE, int val, int value)
{
	List new_list=(List)malloc(sizeof(struct listitem));
	if (*head == NULL)
		return NULL;
	if (head == new_list)
	{
	new_list->number=value;
	new_list->name[0]='\0';
	new_list->next=*head;
	*head=new_list;
		return *head;
	}
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->next == new_list)
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
void insertback(List* head, int val)
{
	if (*head == NULL)
	{
		return prepend(head, val);
	}
	List cursor = *head;
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	List new_list = (List)malloc(sizeof(struct listitem));
	new_list->number = val++;
    new_list->name[0] = '\0';
    new_list->next = NULL;
    cursor->next = new_list;
}
void insertfronte(List* head, int SIZE, char* str)
{
	List new_list=(List)malloc(sizeof(struct listitem));
	if (*head == NULL)
		return NULL;
	if (head == new_list)
	{
	new_list->number=str;
	new_list->name[0]='\0';
	new_list->next=*head;
	*head=new_list;
		return *head;
	}
	List cursor = head;
	while (cursor != NULL)
	{
		if (cursor->next == new_list)
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
void insertbacke(List* head, char* str)
{

}


bool isempty(List* head)
{
		printf("List == NULL");
		return head == NULL;
}

int length(List head)
{
	int count=0;
	List current = head;
	while (current != NULL) {
		count++;
    printf("Number: %d, Name: %s\n", current->number, current->name);
    current = current->next;
	}
}

remove_front(List** head, int value)
{
	if (*head == NULL) 
	{
		return NULL;
	}
    List cursor = *head;
    List prev = NULL;

    // Поиск узла для удаления
    while (cursor != NULL && cursor->number != value) {
        prev = cursor;
        cursor = cursor->next;
    }

    // Если узел не найден
    if (cursor == NULL) 
	{
		return NULL;
	}
    // Если узел - первый элемент
    if (prev == NULL) 
	{
        *head = cursor->next;
    } 
	else 
	{
        prev->next = cursor->next;
    }

    free(cursor);
    return *head;
}
remove_back(List head)
{

}

void destroyItem(List* head, List node)
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
	List cursor = *head;
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


List getitem(List head, int SIZE, int data)
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


List getitems(List head, char* str)
{
	List cursor = head;
	while (cursor != NULL)
	{
		if (strcmp(cursor->name, str)==0)
			return cursor;
		cursor = cursor->next;
	}
	return NULL;
}
#endif /* _LIST_H */