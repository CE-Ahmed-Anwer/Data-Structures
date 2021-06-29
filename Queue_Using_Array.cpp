#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	int* array;
	int front;
	int rear;
	int size;
};

Queue* initQueue(int size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->array = (int*)malloc(size * sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	queue->size = size;
	return queue;
}

int isFull(Queue* queue) {
	return queue->rear == queue->size;
}

int isEmpty(Queue* queue) {
	return queue->front == queue->rear;
}

void enqueue(Queue* queue, int value) {
	if (isFull(queue)) {
		printf("Queue is Full\n");
	}
	else {
		queue->array[queue->rear] = value;
		queue->rear += 1;
	}
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is Empty\n");
		return INT_MIN;
	}
	else {
		int value = queue->array[queue->front];
		queue->front =+ 1;
		if (isEmpty(queue)) {
			queue->front = 0;
			queue->rear = 0;
		}
		return value;
	}
}

void printQueue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is Empty");
	}
	else {
		printf("Front--->");
		for (int i = queue->front; i < queue->rear; i++) {
			printf(" %d ", queue->array[i]);
		}
		printf("<---Rear\n");
	}
}

void main() {
	Queue* queue = initQueue(10);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	int value = dequeue(queue);
	if (value != INT_MIN) {
		printf("%d\n", value);
	}
	printQueue(queue);
}