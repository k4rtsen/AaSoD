#include "node.h"

Node::Node() :
	data(nullptr),
	next(nullptr)
{
	cout << "Node()\n";
}

Node::Node(int x) :
	data(new int(x)),
	next(nullptr)
{
	cout << "Node(int)\n";
}

Node::Node(const Node& node)
{
	this->data = new int();
	*this->data = node.getData();
	this->next = new Node();
	this->next = node.getNext();
}

Node::~Node()
{
	cout << "~Node!\n";
}

void Node::setData(int x)
{
	this->data = new int(x);
}

int Node::getData() const
{
	return this ? *this->data : NULL;
}

void Node::setNext(Node* x)
{
	this->next = x;
}

Node* Node::getNext() const
{
	return this ? this->next : nullptr;
}
