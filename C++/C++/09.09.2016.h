#pragma once
#include <iostream>
#include <string>
#include <vector>

void longest_dist_same_symbol(std::string text) {
	int leftPos = 0, rightPos = 0;
	int maxDist = 0;
	for (int i = 0; i < text.size(); ++i) {
		for (int j = text.size() - 1; j > i; --j) {
			if (text[i] == text[j] && maxDist < (j - i)) {
				leftPos = i;
				rightPos = j;
				maxDist = rightPos - leftPos;
			}
		}
	}

	std::cout << "Max dist for sentence \"" << text << "\"\n" << maxDist << ": " << leftPos << " - " << rightPos;
}

struct TreeNode {
	int value;
	std::vector<TreeNode*> children;
};

TreeNode* build_tree(const std::vector<int>& arr, int index, int k) {
	if (index >= arr.size())
		return nullptr;

	TreeNode* node = new TreeNode;
	node->value = arr[index];

	for (int i = 1; i <= k; ++i)
		node->children.push_back(build_tree(arr, index*k + i, k));

	return node;
}

TreeNode* task2(const std::vector<int>& arr, int k) {
	auto node = build_tree(arr, 0, k);
	std::cout << "Depth is " << (int)(log(arr.size()) / log(k)) + 1;
	return node;
}