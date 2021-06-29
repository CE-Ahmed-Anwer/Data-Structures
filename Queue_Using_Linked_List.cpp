#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	Node* next;
};

typedef struct Queue {
	Node* front;
	Node* rear;
};

Node* initNode(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

Queue* initQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

int isEmpty(Queue* queue) {
	return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
	Node* node = initNode(value);
	if (isEmpty(queue)) {
		queue->front = node;
		queue->rear = node;
	}
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is Empty\n");
		return INT_MIN;
	}
	else {
		int value = queue->front->value;
		Node* node = queue->front;
		queue->front = queue->front->next;
		free(node);
		return value;
	}
}

void printQueue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is Empty\n");
	}
	else {
		Node* pointer = queue->front;
		printf("Front--->");
		while (pointer) {
			printf(" %d ", pointer->value);
			pointer = pointer->next;
		}
		printf("<---Rear\n");
	}
}

void main() {
	Queue* queue = initQueue();
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	int value = dequeue(queue);
	if (value != INT_MIN) {
		printf("%d\n", value);
	}
	printQueue(queue);
}