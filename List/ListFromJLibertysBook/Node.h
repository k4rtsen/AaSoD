#pragma once
#include "Data.h"
class Node
{
public:
	Node();
	virtual ~Node();
	virtual	Node* Insert(Data* data) = 0;
	virtual void Show() = 0;
private:
};

class InternalNode : public Node
{
public:
	InternalNode(Data* data, Node* next);
	~InternalNode();
	virtual Node* Insert(Data* theData);
	virtual void Show() {
		data->Show();
		next->Show();
	}

private:
	Data* data;
	Node* next;
};

class TailNode : public Node
{
public:
	TailNode() {}
	~TailNode() {}
	virtual Node* Insert(Data* theData);
	virtual void Show() {}

private:

};

class HeadNode : public Node
{
public:
	HeadNode();
	~HeadNode();
	virtual Node* Insert(Data* theData);
	virtual void Show() { myNext->Show(); }

private:
	Node* myNext;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList() { delete myHead; }
	void Insert(Data* theData);
	void ShowAll() { myHead->Show(); }
private:
	HeadNode* myHead;
};
