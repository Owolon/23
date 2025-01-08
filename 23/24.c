#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct  Stack {
    int   top;
    TYPE data[NMAX];
    struct Stack *next;
} stack;

int isempty(stack *s);// проверить, если стек пуст {top==0} вернуть 1, иначе 0
int isfull(stack *s);// проверить, если стек полон {top==NMAX-1} вернуть 1, иначе 0
int push(stack *s, TYPE a);//поместить элемент а в стек  {top=top+1, data[top]=a}, если стек не полон
TYPE pop(stack *s);// вернуть элемент {data[top]}, удалив его из стека {top=top-1}, если стек не пуст
TYPE top(stack *s);//вернуть значение элемента в вершине стека {return data[top]}

int isempty(stack *s)
{
    if (top==0) return 1;
    else return 0;
}
int isfull(stack *s)
{
    return
}
void display(stack *s) 
{
    int i = s->top;
    while (i>0)
    printf(TYPE, s->data[i--]);
}

struct  Node {

  TYPE data;

 struct Node * next;

};

typedef struct  
{
    struct  Node *queue;
    struct  Node * front;
    struct  Node * back;
} queue_list;

 void enQueue(queue_list *que, TYPE element);//добавить элемент в очередь
 TYPE deQueue(queue_list *que);//извлечь элемент из очереди

void queue_test()
{
    queue_list Str; // объявление и инициализация очереди 
    Strback=Str. front= NULL;
    char temp[100];
    system("chcp 1251");
    puts("Введите строку"); // вывод строки 
    fgets(temp, NSTR-1, stdin); // заполнение очереди символа из введенной строки 
    for (int i = 0; i < NSTR-1 && temp[i] != '\n' && temp[i]; i++) 
    enQueue(&Str, temp[i]);// печать очереди
    while(Str.front)
    printf(FTYPE, deQueue(&Str));
}