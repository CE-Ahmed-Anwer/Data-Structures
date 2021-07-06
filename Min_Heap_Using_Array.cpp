#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Heap {
	int* arr;
	int count;
	int size;
};

Heap* initHeap(int size) {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->arr = (int*)malloc(size * sizeof(int));
	heap->count = 0;
	heap->size = size;
	return heap;
}

void shiftUp(Heap* heap, int index) {
	int temp;
	int parentIndex = (index - 1) / 2;
	if (heap->arr[index] < heap->arr[parentIndex]) {
		temp = heap->arr[index];
		heap->arr[index] = heap->arr[parentIndex];
		heap->arr[parentIndex] = temp;
		shiftUp(heap, parentIndex);
	}
}

void shiftDown(Heap* heap, int parentIndex) {
	int temp;
	int minIndex;
	int leftChildIndex = parentIndex * 2 + 1;
	int rightChildIndex = parentIndex * 2 + 2;
	if (leftChildIndex >= heap->count) leftChildIndex = -1;
	if (rightChildIndex >= heap->count) rightChildIndex = -1;
	if (leftChildIndex != -1 && heap->arr[leftChildIndex] < heap->arr[parentIndex]) {
		minIndex = leftChildIndex;
	}
	else {
		minIndex = parentIndex;
	}
	if (rightChildIndex != -1 && heap->arr[rightChildIndex] < heap->arr[minIndex]) {
		minIndex = rightChildIndex;
	}
	if (minIndex != parentIndex) {
		temp = heap->arr[parentIndex];
		heap->arr[parentIndex] = heap->arr[minIndex];
		heap->arr[minIndex] = temp;
		shiftDown(heap, minIndex);
	}
}

void insert(Heap* heap, int data) {
	if (heap->count < heap->size) {
		heap->arr[heap->count] = data;
		shiftUp(heap, heap->count);
		heap->count += 1;
	}
	else {
		printf("Heap is Full\n");
	}
}

int popMin(Heap* heap) {
	int data;
	if (heap->count != 0) {
		data = heap->arr[0];
		heap->arr[0] = heap->arr[heap->count - 1];
		heap->count -= 1;
		shiftDown(heap, 0);
	}
	else {
		data = INT_MIN;
	}
	return data;
}

void printHeap(Heap* h) {
	for (int i = 0; i < h->count; i++) {
		printf(" %d ", h->arr[i]);
	}
	printf("\n");
}

void main() {
	Heap* heap = initHeap(100);
	insert(heap, 5);
	insert(heap, 7);
	insert(heap, 6);
	insert(heap, 8);
	insert(heap, 9);
	insert(heap, 10);
	insert(heap, 3);
	popMin(heap);
	printHeap(heap);
}