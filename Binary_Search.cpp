#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int iterativeBinarySearch(int array[], int startIndex, int endIndex, int value) {
    int middle;
    while (startIndex <= endIndex) {
        middle = startIndex + (endIndex - startIndex) / 2;
        if (array[middle] == value) {
            return middle;
        }
        else if (array[middle] < value) {
            startIndex = middle + 1;
        }
        else {
            endIndex = middle - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int array[], int startIndex, int endIndex, int value) {
    if (endIndex >= startIndex) {
        int middle = startIndex + (endIndex - startIndex) / 2;
        if (array[middle] == value) {
            return middle;
        }
        else if (array[middle] > value) {
            return recursiveBinarySearch(array, startIndex, middle - 1, value);
        }
        else {
            return recursiveBinarySearch(array, middle + 1, endIndex, value);
        }
    }
    return -1;
}

void main() {
    int array[] = {1, 9, 11, 15, 19, 120, 231};
    int size = 7;
    int value = 15;
    int index;
    //Iterative Binary Search
    index = iterativeBinarySearch(array, 0, size - 1, value);
    if (index == -1) {
        printf("Value not found in the array\n");
    }
    else {
        printf("Value found at index : %d\n", index);
    }
    //Recursive Binary Search
    index = recursiveBinarySearch(array, 0, size - 1, value);
    if (index == -1) {
        printf("Value not found in the array\n");
    }
    else {
        printf("Value found at index : %d\n", index);
    }
}