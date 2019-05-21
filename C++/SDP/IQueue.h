#pragma once
// Interface for queue
class IQueue
{
public:
	virtual void push(int value) = 0;
	virtual int pop() = 0;
	virtual bool empty() const = 0;
};

