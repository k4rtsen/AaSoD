#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	int* data;
	Node* next;

public:
	Node();
	Node(int);
	Node(const Node&);
	~Node();
	void setData(int);
	int getData() const;
	void setNext(Node*);
	Node* getNext() const;
};
