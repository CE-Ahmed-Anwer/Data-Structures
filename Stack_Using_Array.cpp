#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int* array;
    int size;
    int tos;
};

Stack* initStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(size * sizeof(int));
    stack->size = size;
    stack->tos = 0;
    return stack;
}

void push(Stack* stack, int value)
{
    if (stack->tos == stack->size)
    {
        printf("stack is Full");
    }
    else
    {

        stack->array[stack->tos] = value;
        stack->tos += 1;
    }
}

int pop(Stack* stack)
{
    if (stack->tos == 0)
    {
        printf("Stack is Empty");
    }
    else
    {
        stack->tos -= 1;
        int value = stack->array[stack->tos];
        return value;
    }
}

void print(Stack* stack)
{
    if (stack->tos == 0)
    {
        printf("stack is Empty");
    }
    else
    {
        for (int i = 0; i < stack->tos; i++)
        {
            printf(" %d ", stack->array[i]);
        }
    }
}

void main()
{
    Stack* stack = initStack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    pop(stack);
    print(stack);
}