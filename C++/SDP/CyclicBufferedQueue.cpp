#include <iostream>
#include "CyclicBufferedQueue.h"

CyclicBufferedQueue::CyclicBufferedQueue()
	:capacity(2), write(0), read(0)
{
	this->data = new int[capacity];
}

void CyclicBufferedQueue::push(int value)
{
	// container is full when we try to write on position which holds value
	if (!empty() && write % capacity == read % capacity)
		this->resize();

	std::cout << "Inserting value " << value << "\n";
	data[write++ % capacity] = value;
}

int CyclicBufferedQueue::pop()
{
	return data[read++ % capacity];
}

bool CyclicBufferedQueue::empty() const
{
	return read == write;
}

void CyclicBufferedQueue::resize()
{
	int newCapacity = capacity * 2;
	std::cout << "resizing container from " << capacity << " to " << newCapacity << "\n";
	auto resized = new int[newCapacity];

	// Remap items in contaier to be sequential in the new memory
	int cRead = read;
	int current = 0;
	while (cRead < write)
		resized[current++] = data[cRead++ % capacity];

	read = 0;
	write = capacity;
	delete[] data;
	data = resized;
	capacity = newCapacity;
}
