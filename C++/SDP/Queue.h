#pragma once
#include <iostream>
#include "Queueable.h"

class Queue: public IQueueable
{
public:
	Queue();
	~Queue();

	void push(int value);
	int pop();
	bool empty()const;

private:
	int* data;
	int capacity;
	int write;
	int read;

	void resize();
};


Queue::Queue()
	:capacity(2), write(-1), read(-1)
{
	this->data = new int[capacity];
}

Queue::~Queue()
{
	delete[] this->data;
}

void Queue::resize() {
	int newCapacity = capacity * 2;
	std::cout << "resizing container from " << capacity << " to " << newCapacity << "\n";
	auto resized = new int[newCapacity];
	for (int i = 0; i < capacity; ++i)
		resized[i] = data[i];
	delete[] data;
	data = resized;
	capacity = newCapacity;
}

void Queue::push(int value) {
	if (write == capacity - 1)
		this->resize();
	data[++write] = value;
}

int Queue::pop() {
	return data[++read];
}

bool Queue::empty()const {
	return read == write;
}
