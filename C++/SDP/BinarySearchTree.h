#pragma once
#include <iostream>
#include <vector>

class BinarySearchTree
{
private:
	struct TreeNode
	{
		int value;
		TreeNode * left;
		TreeNode * right;
	};

	TreeNode * root;

	void release(TreeNode* node) {
		if (node == nullptr)
			return;
		release(node->left);
		release(node->right);
		delete node;
	}

	bool search(int value, TreeNode * node) const {
		if (node == nullptr)
			return false;
		if (value == node->value)
			return true;

		if (value < node->value)
			return search(value, node->left);
		else
			return search(value, node->right);
	}

	void add(int value, TreeNode *& node) {
		if (node == nullptr)
			node = new TreeNode{ value, nullptr, nullptr };
		if (value == node->value)
			return;
		if (value < node->value)
			add(value, node->left);
		if (value > node->value)
			add(value, node->right);
	}

	void print(TreeNode * node) const {
		if (node == nullptr)
			return;
		print(node->left);
		std::cout << node->value << " ";
		print(node->right);
	}

public:
	BinarySearchTree()
		:root(nullptr) { }
	~BinarySearchTree() {
		release(root);
	}

	bool search(int value) const {
		return search(value, root);
	}

	void add(int value) {
		add(value, root);
	}

	void add(const std::vector<int>& values) {
		for (auto && value : values)
			add(value, root);
	}

	void print() {
		print(root);
	}
};
