#include "Node.h"


Node::Node()
{
}

Node::~Node()
{
}

InternalNode::InternalNode(Data* data, Node* next) :
	data(data),
	next(next)
{

}

InternalNode::~InternalNode()
{
	delete data;
	delete next;
}

Node* InternalNode::Insert(Data* theData)
{
	int result = data->Compare(*theData);

	switch (result)
	{
	case kIsSame:
	case kIsSmaller:
		next = next->Insert(theData);
		return this;
	case kIsLarger:
		InternalNode* dataNode = new InternalNode(theData, this);
		return dataNode;
	}
	return this;
}

Node* TailNode::Insert(Data* theData)
{
	InternalNode* dataNode = new InternalNode(theData, this);
	return dataNode;
}

HeadNode::HeadNode()
{
	myNext = new TailNode;
}

HeadNode::~HeadNode()
{
	delete myNext;
}

Node* HeadNode::Insert(Data* theData)
{
	myNext = myNext->Insert(theData);
	return this;
}

LinkedList::LinkedList()
{
	myHead = new HeadNode();
}

void LinkedList::Insert(Data* theData)
{
	myHead->Insert(theData);
}
