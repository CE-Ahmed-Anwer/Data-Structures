#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	Node* next;
};

typedef struct Deque {
	Node* head;
	Node* tail;
};

Node* initNode(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
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
		deque->tail->next = node;
		deque->tail = node;
	}
}

void removeFromHead(Deque* deque) {
	if (deque->head == NULL) {
		printf("Deque is Empty\n");
	}
	else if (deque->head == deque->tail) {
		free(deque->head);
		deque->head = NULL;
		deque->tail = NULL;
	}
	else {
		Node* p = deque->head;
		deque->head = deque->head->next;
		free(p);
	}
}

void removeFromTail(Deque* deque) {
	if (deque->head == NULL) {
		printf("Deque is Empty\n");
	}
	else if (deque->head == deque->tail) {
		free(deque->head);
		deque->head = NULL;
		deque->tail = NULL;
	}
	else {
		Node* p = deque->head;
		while (p->next != deque->tail) {
			p = p->next;
		}
		p->next = NULL;
		free(deque->tail);
		deque->tail = p;
	}
}

void printDeque(Deque* deque) {
	if (deque->head == deque->tail) {
		printf("Deque is Empty\n");
	}
	else {
		Node* p = deque->head;
		printf("Head--->");
		while (p != NULL) {
			printf(" %d ", p->value);
			p = p->next;
		}
		printf("<---Tail\n");
	}
}

int size(Deque* deque) {
	int size = 0;
	Node* p = deque->head;
	while (p) {
		size += 1;
		p = p->next;
	}
	return size;
}

void main() {
	Deque* deque = initDeque();
	insertAtHead(deque, 4);
	insertAtHead(deque, 3);
	insertAtHead(deque, 2);
	insertAtHead(deque, 1);
	insertAtTail(deque, 5);
	insertAtTail(deque, 6);
	insertAtTail(deque, 7);
	printDeque(deque);
}