#include "list.h"

list::list() :
	head(nullptr),
	last(nullptr)
{
	cout << "list!\n";
}

list::list(const list& theList)
{
	Node* pointer = theList.getHead();
	while (pointer) {
		// Доделать!!!
		cout << "Finish up it!";
	}
	this->head = new Node(*theList.getHead());
}

list::~list()
{
	cout << "~list\n";
	while (head) // head != nullptr
	{
		Node* pointer = this->head;
		this->head = this->head->getNext();
		delete pointer;
	}
}

void list::setHead(Node* n)
{
	this->head = n;
}

Node* list::getHead() const
{
	return this->head;
}

void list::setLast(Node* n)
{
	this->last = n;
}

Node* list::getLast() const
{
	return this->last;
}

bool list::is_empty() const
{
	return this->head == nullptr;
}

void list::push_back(int x)
{
	Node* p = new Node(x);
	if (this->is_empty())
	{
		this->head = p;
		this->last = p;
		return;
	}
	this->last->setNext(p);
	this->last = p;
}

void list::pull_end()
{
	if (this->is_empty()) {
		cout << "This list is empity.\n";
		return;
	}
	if (head == last) {
		this->pull_front();
		return;
	}
	Node* pointer = head;
	while (pointer->getNext() != last) pointer = pointer->getNext();
	pointer->setNext(nullptr);
	delete last;
	last = pointer;
}

void list::pull_front()
{
	if (this->is_empty()) {
		cout << "This list is empity.\n";
		return;
	}
	Node* pointer = this->head;
	this->head = head->getNext();
	delete pointer;
}

Node* list::find(int data)
{
	Node* p = head;
	while (p && p->getData() != data)
		p = p->getNext();
	return (p && p->getData() == data) ? p : nullptr;
}

void list::clear()
{
	if (this->is_empty())
	{
		cout << "List is clear.\n";
		return;
	}

	while (head) // head != nullptr
	{
		Node* pointer = this->head;
		this->head = this->head->getNext();
		delete pointer;
	}
	cout << "List is clear.\n";
}

void list::show_all() const
{
	if (this->is_empty())
	{
		cout << "This list is empity.\n";
		return;
	}
	Node* pointer = this->head;
	while (pointer) // pointer != nullptr
	{
		cout << pointer->getData() << ", ";
		pointer = pointer->getNext();
	}
	cout << endl;
}
