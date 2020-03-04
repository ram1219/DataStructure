/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.03.03

  배열을 이용한 스택 
*/

#include <stdio.h>
#include <stdbool.h>

typedef int Items;
typedef struct Stack Stack;

#define InitSize 5

struct Stack {
    Items* items;          // 스택의 데이터를 저장할 배열 공간
    int capacity;          // 스택의 전체 크기
    int top;               // 스택의 제일 윗부분 (LIFO : Last In First Out)
};

// 함수선언
Stack* CreateStack();
void PushStack(Stack* stack, int item);
bool IsFull_Stack(const Stack* stack);
void Expand_Stack(Stack* stack);
Items PeekStack(const Stack* stack);
Items PopStack(Stack* stack);
bool IsEmpty_Stack(const Stack* stack);
void ViewStack(const Stack* stack);
void ReleaseStack(Stack* stack);

// 메인함수
int main()
{
    // 스택 생성
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

// 스택 생성 및 초기화 함수
Stack* CreateStack()
{
    // 스택 구조체 생성 및 동적할당
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    // 스택 구조체 변수 초기화
    stack->items = (Items*)malloc(sizeof(Items) * InitSize);
    stack->capacity = InitSize;
    stack->top = -1;

    return stack;
}

// 스택에 데이터 추가
void PushStack(Stack* stack, int item)
{
    // stack의 top 
    stack->top++;

    // 스택의 공간이 가득 찬 경우 공간을 확장한다.
    if (IsFull_Stack == true) {
        Expand_Stack(stack);
    }
  
    stack->items[stack->top] = item;
}

// 스택의 공간이 가득 찼을 경우 true를 return
bool IsFull_Stack(const Stack* stack)
{
    return stack->top + 1 == stack->capacity ? true : false;
}

// stack의 공간이 가득 찬 경우 호출되어 스택 공간 확장.
void Expand_Stack(Stack* stack)
{
    // stack의 데이터가 들어갈 Items 배열 공간 확장
    Items* items = (Items*)malloc(sizeof(Items) * stack->capacity * 2);

    // 스택의 top까지 stack->items 배열에 저장된 데이터를 위에서 확장한 items의 배열에 옮겨 저장한다.
    for (int i = 0; i <= stack->top; i++) {
        items[i] = stack->items[i];
    }
    // 할당 받은 공간을 해제한다.
    free(stack->items);

    // 스택의 전체 공간을 늘인다.
    stack->capacity *= 2;
    // 이 함수에서 할당한 공간을 Stack에 전달한다. 
    stack->items = items;
}

// top이 가지고 있는 데이터를 return
Items PeekStack(const Stack* stack)
{
    if (IsEmpty_Stack == true) {
        printf("Empty Stack\n");
        return;
    }

    return stack->items[stack->top];
}

// stack의 top을 pop 한 후 top이 가지고 있던 데이터를 return한다.
Items PopStack(Stack* stack)
{
    // Pop 되기전에 top이 가지고 있을 데이터를 저장할 변수
    Items item;

    if (IsEmpty_Stack == true) {
        printf("Empty Stack\n");
        return;
    }

    item = stack->items[stack->top];
    stack->top--;

    return item;
}

// stack이 비어있는 경우 true를 return
bool IsEmpty_Stack(const Stack* stack)
{
    return stack->top == -1 ? true : false;
}

// 스택이 가지고 있는 데이터를 출력한다.
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

// 동적 할당 받은 공간 해제
void ReleaseStack(Stack* stack)
{
    free(stack->items);
    free(stack);
}
