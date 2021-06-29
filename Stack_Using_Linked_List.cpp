#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

//Declare linked list node
typedef struct Node {
	int data;
	Node* next;
};

//Declare stack which is a top of stack pointer
typedef struct Stack {
	Node* tos;
};

//Function to initialize node
Node* initNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//Function to initialize stack
Stack* initStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->tos = NULL;
	return stack;
}

//Stack Function to check if the stack is empty or not
int isEmpty(Stack* stack) {
	return stack->tos == NULL;
}

//Satck function to return top element in a stack without removing it
int peek(Stack* stack) {
	if (!isEmpty(stack)) {
		return stack->tos->data;
	}
	printf("Stack is Empty\n");
	return INT_MIN;
}

//Stack function to add an element
//insert new data at the beginning
void push(Stack* stack, int data) {
	Node* node = initNode(data);
	if (isEmpty(stack)) {
		stack->tos = node;
	}
	else {
		node->next = stack->tos;
		stack->tos = node;
	}
}


//Stack function to reuturn top element of stack and remove it
int pop(Stack* stack) {
	int data;
	if (isEmpty(stack)) {
		data = INT_MIN;
		printf("Stack is Empty\n");
	}
	else {
		Node* node = stack->tos;
		stack->tos = stack->tos->next;
		data = node->data;
		free(node);
	}
	return data;
}

//function print all elements in a stack
void printStack(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is Empty\n");
	}
	else {
		Node* pointer = stack->tos;
		printf("Top Of Stack");
		while (pointer) {
			printf("---> %d ", pointer->data);
			pointer = pointer->next;
		}
		printf("\n");
	}
}

void main() {
	Stack* stack = initStack();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	push(stack, 6);
	pop(stack);
	printStack(stack);
}