#include <iostream>
#include "Queue.h"
#include "CyclicBufferedQueue.h"

class Stack {
private:
	struct StackNode {
		int value;
		StackNode* prev;
	};

	StackNode* current;

public:
	Stack()
		:current(nullptr){ }
	~Stack() {
		StackNode* prev;
		while (!empty()) {
			prev = current->prev;
			delete current;
			current = prev;
		}
	}

	void push(int value) {
		auto next = new StackNode;
		next->value = value;
		next->prev = current;
		current = next;
	}

	int pop() {
		if (empty())
			throw "Cannot pop from empty stack";

		auto prev = current->prev;
		int value = current->value;
		delete current;
		current = prev;
		return value;
	}

	bool empty() {
		return current == nullptr;
	}
};

void test_dynamic_queue() {
	IQueueable * queue = new Queue;
	std::cout << "Queue test:\n";
	for (int i = 0; i <= 15; ++i)
		queue->push(i);
	while (!queue->empty())
		std::cout << queue->pop() << " ";

	delete queue;

	std::cout << "\n\nCyclic-buffered queue test:\n";
	queue = new CyclicBufferedQueue;
	for (int i = 0; i < 8; ++i)
		queue->push(i);

	for (int i = 0; i < 4; ++i)
		std::cout << queue->pop() << " ";
	std::cout << "\n";

	for (int i = 8; i <= 16; ++i)
		queue->push(i);

	while (!queue->empty())
		std::cout << queue->pop() << " ";

	//delete queue;
}

void test_linked_stack() {
	Stack stack;
	for (int i = 0; i <= 15; ++i)
		stack.push(i);
	while (!stack.empty())
		std::cout << stack.pop() << " ";
}


int main() {
	test_dynamic_queue();
	//test_linked_stack();
	return 0;
}