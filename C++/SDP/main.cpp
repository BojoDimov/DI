#include <iostream>
#include "Queue.h"
#include "CyclicBufferedQueue.h"
#include "Stack.h"
#include "BinarySearchTree.h"

void test_dynamic_queue() {
	IQueue * queue = new Queue;
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
	Stack<int> stack;
	for (int i = 0; i <= 15; ++i)
		stack.push(i);
	while (!stack.empty())
		std::cout << stack.pop() << " ";
}

void test_bst() {
	BinarySearchTree tree;
	tree.add({ 9, 5, 15, 1, 3, 6, 12, 16 });
	tree.add(3);
	tree.add(4);
	tree.print();
	std::cout << "\nFind 4? " << tree.search(4) << "\nFind 100? " << tree.search(100) << std::endl;
}

struct Vertex {
	int value;
};

struct Edge {
	int source;
	int dest;
};

class Graph {
private:
	std::vector<Vertex> V;
	std::vector<Edge> E;

public:
	//Data Encapsulation
	void addVertex(int value) {

	}

	void addEdge(int source, int dest) {

	}

	void removeVertex(int value) {

	}

	void removeEdge(int source, int dest) {

	}
};

class Tree : public Graph {
public:
	void addEdge(int source, int dest) {
		//check if we are not making cycles
		Graph::addEdge(source, dest);
	}
};

//Abstraction
class WeightedStructure {
public:
	virtual float getScore() = 0;
};

//Multiple inheritance
class WeightedGraph : public virtual Graph, public WeightedStructure {

};

//Diamond problem
class MinimalSpanningTree : public Tree, public WeightedGraph {

};


int main(int argc, char ** argv) {
	//test_linked_stack();
	//test_dynamic_queue();
	//test_bst();
	return 0;
}