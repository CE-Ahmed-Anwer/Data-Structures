#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* initNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* findMinimum(Node* root) {
	if (!root) 
		return NULL;
	else if (root->left) 
		return findMinimum(root->left);
	return root;
}

Node* search(Node* root, int data) {
	if (!root || data == root->data)
		return root;
	else if (data > root->data)
		return search(root->right, data);
	else
		return search(root->left, data);
}

Node* insert(Node* root, int data) {
	if (!root) 
		return initNode(data);
	else if (data > root->data) 
		root->right = insert(root->right, data);
	else if (data < root->data)
		root->left = insert(root->left, data);
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (!root) 
		return NULL;
	if (data > root->data) 
		root->right = deleteNode(root->right, data);
	else if (data < root->data) 
		root->left = deleteNode(root->left, data);
	else {
		if (!root->left && !root->right) {
			free(root);
			return NULL;
		}
		else if (!root->left || !root->right) {
			Node* temp;
			if (root->left)
				temp = root->left;
			else
				temp = root->right;
			free(root);
			return temp;
		}
		else {
			Node* temp = findMinimum(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

void printPreorder(Node* root) {
	if (root) {
		printf(" %d ", root->data);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printInorder(Node* root) {
	if (root) {
		printInorder(root->left);
		printf(" %d ", root->data);
		printInorder(root->right);
	}
}

void printPostorder(Node* root) {
	if (root) {
		printPostorder(root->left);
		printPostorder(root->right);
		printf(" %d ", root->data);
	}
}

void main() {
	Node* root;
	root = initNode(20);
	insert(root, 6);
	insert(root, 1);
	insert(root, 16);
	insert(root, 9);
	insert(root, 8);
	insert(root, 12);
	insert(root, 32);
	insert(root, 27);
	insert(root, 42);
	insert(root, 46);
	insert(root, 46);
	printInorder(root);
	printf("\n");
	root = deleteNode(root, 9);
	printInorder(root);
	Node* node = search(root, 27);
	if (node) {
		printf("\n %d", node->data);
	}
}