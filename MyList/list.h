#pragma once
#include "node.h"
class list
{
private:
	Node* head;
	Node* last;

public:
	list();
	list(const list& theList);
	~list();
	// access to private property
	void setHead(Node*);
	Node* getHead() const;
	void setLast(Node*);
	Node* getLast() const;
	// methods
	bool is_empty() const;
	void push_back(int);
	void pull_end();
	void pull_front();
	Node* find(int);
	void clear();
	void show_all() const;
};
