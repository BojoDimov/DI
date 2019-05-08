#pragma once
#include <iostream>
#include <string>

/// TASK 1
int reverse(int a) {
	int result = 0;

	while (a > 0) {
		result = result * 10 + a % 10;
		a /= 10;
	}

	return result;
}

bool ltLex(int a, int b) {
	a = reverse(a);
	b = reverse(b);

	while (a > 0 && b > 0) {
		if (a % 10 > b % 10)
			return false;
		else if (a % 10 < b % 10)
			return true;

		a /= 10;
		b /= 10;
	}

	if (a > b)
		return false;
	return true;
}

void sortLex(int* arr, int n) {
	int temp;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (ltLex(arr[j], arr[i])) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}


void print(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
}

void test_task1() {
	std::cout << "######### TASK 1 TESTS ###########\n";
	int a[6] = { 13,14,7,2018,9,0 };
	std::cout << "Original:\n";
	print(a, 6);
	sortLex(a, 6);
	std::cout << "\nSorted:\n";
	print(a, 6);
}

/// TASK 2
struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* middle;
	TreeNode* right;
};

int maxDepth(TreeNode* node) {
	if (node == nullptr)
		return 0;

	int ld = maxDepth(node->left);
	int md = maxDepth(node->middle);
	int rd = maxDepth(node->right);

	int max1 = ld < md ? md : ld;
	return  (max1 < rd ? rd : max1) + 1;
}

std::string readAtDepth(TreeNode* node, int depth) {
	if (node == nullptr)
		return "";

	if (depth == 0)
		return std::string(1, node->data);

	return readAtDepth(node->left, depth - 1) + readAtDepth(node->middle, depth - 1) + readAtDepth(node->right, depth - 1);
}

std::string readLast(TreeNode* root) {
	int depth = maxDepth(root) - 1;
	return readAtDepth(root, depth);
}

std::string serialize(TreeNode* node) {
	if (node == nullptr)
		return "*";
	return "(" +
		std::string(1, node->data) + " " +
		serialize(node->left) + " " +
		serialize(node->middle) + " " +
		serialize(node->right) +
		")";
}

void test_task2() {
	std::cout << "\n\n######### TASK 2 TESTS ###########\n";
	TreeNode root = {
		'b',
		new TreeNode{
		'x',
		new TreeNode{ 'p',nullptr,nullptr,nullptr },
		new TreeNode{ 'q',nullptr,nullptr,nullptr },
		new TreeNode{
		'r',
		new TreeNode{ 'c',nullptr,nullptr,nullptr },
		nullptr,
		new TreeNode{ 'a',nullptr,nullptr,nullptr }
	}
	},
		new TreeNode{
		'y',
		nullptr,
		nullptr,
		new TreeNode{
		's',
		nullptr,
		new TreeNode{ 't', nullptr, nullptr, nullptr },
		nullptr
	}
	},
		nullptr
	};
	std::cout << readLast(&root);
	std::cout << "\n" << serialize(&root);
}