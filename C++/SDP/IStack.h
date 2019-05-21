#pragma once
template<typename T>
class IStack
{
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual bool empty() const = 0;
};

