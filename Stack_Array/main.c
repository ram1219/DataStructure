/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.03.03

  �迭�� �̿��� ���� 
*/

#include <stdio.h>
#include <stdbool.h>

typedef int Items;
typedef struct Stack Stack;

#define InitSize 5

struct Stack {
    Items* items;          // ������ �����͸� ������ �迭 ����
    int capacity;          // ������ ��ü ũ��
    int top;               // ������ ���� ���κ� (LIFO : Last In First Out)
};

// �Լ�����
Stack* CreateStack();
void PushStack(Stack* stack, int item);
bool IsFull_Stack(const Stack* stack);
void Expand_Stack(Stack* stack);
Items PeekStack(const Stack* stack);
Items PopStack(Stack* stack);
bool IsEmpty_Stack(const Stack* stack);
void ViewStack(const Stack* stack);
void ReleaseStack(Stack* stack);

// �����Լ�
int main()
{
    // ���� ����
    Stack* stack = CreateStack();

    printf("PUSH : 10\t");    PushStack(stack, 10);   ViewStack(stack);
    printf("PUSH : 20\t");    PushStack(stack, 20);   ViewStack(stack);
    printf("PUSH : 30\t");    PushStack(stack, 30);   ViewStack(stack);
    printf("PUSH : 40\t");    PushStack(stack, 40);   ViewStack(stack);
    printf("PUSH : 50\t");    PushStack(stack, 50);   ViewStack(stack);
    printf("PUSH : 60\t");    PushStack(stack, 60);   ViewStack(stack);

    printf("PEEK : %d\t", PeekStack(stack));    ViewStack(stack);

    printf("POP : %d\t", PopStack(stack));      ViewStack(stack);
    printf("POP : %d\t", PopStack(stack));      ViewStack(stack);
    printf("POP : %d\t", PopStack(stack));      ViewStack(stack);

    ReleaseStack(stack);
}

// ���� ���� �� �ʱ�ȭ �Լ�
Stack* CreateStack()
{
    // ���� ����ü ���� �� �����Ҵ�
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    // ���� ����ü ���� �ʱ�ȭ
    stack->items = (Items*)malloc(sizeof(Items) * InitSize);
    stack->capacity = InitSize;
    stack->top = -1;

    return stack;
}

// ���ÿ� ������ �߰�
void PushStack(Stack* stack, int item)
{
    // stack�� top 
    stack->top++;

    // ������ ������ ���� �� ��� ������ Ȯ���Ѵ�.
    if (IsFull_Stack == true) {
        Expand_Stack(stack);
    }
  
    stack->items[stack->top] = item;
}

// ������ ������ ���� á�� ��� true�� return
bool IsFull_Stack(const Stack* stack)
{
    return stack->top + 1 == stack->capacity ? true : false;
}

// stack�� ������ ���� �� ��� ȣ��Ǿ� ���� ���� Ȯ��.
void Expand_Stack(Stack* stack)
{
    // stack�� �����Ͱ� �� Items �迭 ���� Ȯ��
    Items* items = (Items*)malloc(sizeof(Items) * stack->capacity * 2);

    // ������ top���� stack->items �迭�� ����� �����͸� ������ Ȯ���� items�� �迭�� �Ű� �����Ѵ�.
    for (int i = 0; i <= stack->top; i++) {
        items[i] = stack->items[i];
    }
    // �Ҵ� ���� ������ �����Ѵ�.
    free(stack->items);

    // ������ ��ü ������ ���δ�.
    stack->capacity *= 2;
    // �� �Լ����� �Ҵ��� ������ Stack�� �����Ѵ�. 
    stack->items = items;
}

// top�� ������ �ִ� �����͸� return
Items PeekStack(const Stack* stack)
{
    if (IsEmpty_Stack == true) {
        printf("Empty Stack\n");
        return;
    }

    return stack->items[stack->top];
}

// stack�� top�� pop �� �� top�� ������ �ִ� �����͸� return�Ѵ�.
Items PopStack(Stack* stack)
{
    // Pop �Ǳ����� top�� ������ ���� �����͸� ������ ����
    Items item;

    if (IsEmpty_Stack == true) {
        printf("Empty Stack\n");
        return;
    }

    item = stack->items[stack->top];
    stack->top--;

    return item;
}

// stack�� ����ִ� ��� true�� return
bool IsEmpty_Stack(const Stack* stack)
{
    return stack->top == -1 ? true : false;
}

// ������ ������ �ִ� �����͸� ����Ѵ�.
void ViewStack(const Stack* stack)
{
    if (IsEmpty_Stack == true) {
        printf("EMPTY STACK\n");
    }
    else {
        printf("[ ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("]\n");
    }
}

// ���� �Ҵ� ���� ���� ����
void ReleaseStack(Stack* stack)
{
    free(stack->items);
    free(stack);
}
