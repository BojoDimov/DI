#pragma once
// Interface for queue
class IQueueable
{
public:
	virtual ~IQueueable() = 0;
	virtual void push(int value) = 0;
	virtual int pop() = 0;
	virtual bool empty() const = 0;
private:
	virtual void resize() = 0;
};

