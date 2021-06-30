#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	Node* next;
	Node* prev;
};

typedef struct Deque {
	Node* head;
	Node* tail;
};

Node* initNode(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

Deque* initDeque() {
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	deque->head = NULL;
	deque->tail = NULL;
	return deque;
}

void insertAtHead(Deque* deque, int value) {
	Node* node = initNode(value);
	if (deque->head == NULL) {
		deque->head = node;
		deque->tail = node;
	}
	else {
		node->next = deque->head;
		deque->head->prev = node;
		deque->head = node;
	}
}

void insertAtTail(Deque* deque, int value) {
	Node* node = initNode(value);
	if (deque->head == NULL) {
		deque->head = node;
		deque->tail = node;
	}
	else {
		node->prev = deque->tail;
		deque->tail->next = node;
		deque->tail = node;
	}
}

void deleteFromHead(Deque* deque) {
	if (deque->head == NULL) {
		printf("Deque is Empty\n");
	}
	else if (deque->head == deque->tail) {
		free(deque->head);
		deque->head = NULL;
		deque->tail = NULL;
	}
	else {
		Node* node = deque->head;
		deque->head = deque->head->next;
		deque->head->prev = NULL;
		free(node);
	}
}

void deleteFromTail(Deque* deque) {
	if (deque->tail == NULL) {
		printf("Deque is Empty\n");
	}
	else if (deque->head == deque->tail) {
		free(deque->tail);
		deque->head = NULL;
		deque->tail = NULL;
	}
	else {
		Node* node = deque->tail;
		deque->tail = deque->tail->prev;
		deque->tail->next = NULL;
		free(node);
	}
}

void printDeque(Deque* deque) {
	Node* node = deque->head;
	if (!node) {
		printf("Deque is Empty\n");
	}
	else {
		printf("Head--->");
		while (node) {
			printf(" %d ", node->value);
			node = node->next;
		}
		printf("<---Tail\n");
	}
}

void printReverseDeque(Deque* deque) {
	Node* node = deque->tail;
	if (!node) {
		printf("Deque is Empty\n");
	}
	else {
		printf("Tail--->");
		while (node) {
			printf(" %d ", node->value);
			node = node->prev;
		}
		printf("<---Head\n");
	}
}

void main() {
	Deque* deque = initDeque();
	printDeque(deque);
	printReverseDeque(deque);

	insertAtHead(deque, 3);
	insertAtHead(deque, 2);
	insertAtHead(deque, 1);
	insertAtTail(deque, 4);
	insertAtTail(deque, 5);
	insertAtTail(deque, 6);
	printDeque(deque);
	printReverseDeque(deque);

	deleteFromHead(deque);
	deleteFromTail(deque);
	printDeque(deque);
	printReverseDeque(deque);
}