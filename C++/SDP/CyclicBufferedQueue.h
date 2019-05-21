#pragma once
#include "IQueue.h"

class CyclicBufferedQueue : public IQueue
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

	void resize();
};

