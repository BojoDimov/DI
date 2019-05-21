#pragma once
#include "IStack.h"

template<typename T>
class Stack : public IStack<T>
{
private:
	struct StackNode {
		T value;
		StackNode * prev;
	};

	StackNode * current;
public:
	Stack();
	~Stack();

	void push(T value);
	T pop();
	bool empty()const;
};


template<typename T>
Stack<T>::Stack()
	:current(nullptr)
{
}

template<typename T>
Stack<T>::~Stack()
{
	StackNode * prev;
	while (!empty()) {
		prev = current->prev;
		delete current;
		current = prev;
	}
}

template<typename T>
void Stack<T>::push(T value)
{
	auto next = new StackNode;
	next->value = value;
	next->prev = current;
	current = next;
}

template<typename T>
T Stack<T>::pop()
{
	if (empty())
		throw "Cannot pop from empty stack";

	auto prev = current->prev;
	auto value = current->value;
	delete current;
	current = prev;
	return value;
}

template<typename T>
bool Stack<T>::empty() const
{
	return current == nullptr;
}
