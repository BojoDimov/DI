#pragma once
#include <iostream>

/// TASK 1
int area(int arr[100][100], int m, int n, int y, int x) {
	if (x < 0 || x >= n || y < 0 || y >= m || arr[y][x] != '4')
		return 0;

	arr[y][x] = 'S';
	int result = 1 + area(arr, m, n, y, x + 1) + area(arr, m, n, y + 1, x) + area(arr, m, n, y, x - 1) + area(arr, m, n, y - 1, x);
	arr[y][x] = '4';
	return result;
}

int maxArea(int arr[100][100], int  m, int  n) {
	int max = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int areaFromCurrentPos = area(arr, m, n, i, j);
			if (max < areaFromCurrentPos)
				max = areaFromCurrentPos;
		}
	}
	return max;
}

void test_task1() {
	int arr[100][100] = {
		{ 'R', 'R' , '1' , '1' ,'2' ,'2' },
		{ '1', 'R' , 'R' , 'R' ,'1' ,'2' },
		{ 'S', '1' , 'R' , 'R' ,'2' ,'3' },
		{ '4', '4' , 'S' , 'S' ,'R' ,'R' },
	};
	std::cout << maxArea(arr, 4, 6);
}



/// TASK 2
template<typename TData>
struct ListNode {
	TData data;
	ListNode<TData>* next;
};

bool isSorted(ListNode<int>* list) {
	ListNode<int>* current = list;
	while (current->next != nullptr) {
		if (current->data > current->next->data)
			return false;
		current = current->next;
	}
	return true;
}

void addToList(ListNode<int> *& result, ListNode<int> *& current, int data) {
	if (current == nullptr) {
		current = new ListNode<int>{ data, nullptr };
		result = current;
	}
	else {
		current->next = new ListNode<int>{ data, nullptr };
		current = current->next;
	}
}

ListNode<int>* merge(ListNode<int>* list1, ListNode<int>* list2) {
	ListNode<int>* result = nullptr;
	ListNode<int>* current = nullptr;

	while (list1 != nullptr && list2 != nullptr) {
		if (list1->data <= list2->data) {
			addToList(result, current, list1->data);
			list1 = list1->next;
		}
		else {
			addToList(result, current, list2->data);
			list2 = list2->next;
		}
	}

	while (list1 != nullptr) {
		addToList(result, current, list1->data);
		list1 = list1->next;
	}

	while (list2 != nullptr) {
		addToList(result, current, list2->data);
		list2 = list2->next;
	}

	return result;
}

void destroyList(ListNode<int>* list) {
	if (list == nullptr)
		return;

	auto current = list;
	auto next = list->next;

	while (current->next != nullptr) {
		delete current;
		current = next;
		next = next->next;
	}
	delete current;
}

ListNode<int>* flattenSorted(ListNode<ListNode<int>*>* lists) {
	ListNode<int>* result = nullptr;
	ListNode<int>* current = nullptr;

	while (lists != nullptr) {
		if (isSorted(lists->data)) {
			if (result == nullptr)
				result = lists->data;
			else {
				current = merge(result, lists->data);
				destroyList(result);
				result = current;
			}
		}
		lists = lists->next;
	}
	return result;
}

void print(ListNode<int>* list) {
	while (list != nullptr) {
		std::cout << list->data << " ";
		list = list->next;
	}
}

void test_task2() {
	auto root = new ListNode<ListNode<int>*>{
		new ListNode<int>{ 4,new ListNode<int>{ 6, new ListNode<int>{ 7, nullptr } } },
		nullptr
	};

	root->next = new ListNode<ListNode<int>*>{
		new ListNode<int>{ 2,new ListNode<int>{ 1, new ListNode<int>{ 3, nullptr } } },
		nullptr
	};

	root->next->next = new ListNode<ListNode<int>*>{
		new ListNode<int>{ 1,new ListNode<int>{ 2, new ListNode<int>{ 2, nullptr } } },
		nullptr
	};

	root->next->next->next = new ListNode<ListNode<int>*>{
		new ListNode<int>{ 3,new ListNode<int>{ 5, new ListNode<int>{ 10, nullptr } } },
		nullptr
	};

	auto res = flattenSorted(root);
	print(res);
}
