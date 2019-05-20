#pragma once
#include "Queueable.h"

class CyclicBufferedQueue : public IQueueable
{
public:
	CyclicBufferedQueue();
	~CyclicBufferedQueue() {
		delete[] data;
	}

	// Inherited via IQueueable
	void push(int value);
	int pop();
	bool empty() const;

private:
	int* data;
	int capacity;
	int write;
	int read;

	// Inherited from IQueueable
	void resize();
};

