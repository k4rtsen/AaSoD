#include "List.h"
#include <iostream>

using namespace std;

template<typename Item>
List<Item>::List() :
	size{ 0 },
	head{ nullptr }
{
	cout << "List constructor." << endl;
}

template<typename Item>
List<Item>::~List()
{
	clear();
	cout << "List destructor." << endl;
}

template<typename Item>
void List<Item>::push_back(Item item)
{
	if (!this->head) {
		head = new Node<Item>(item); // � next ��������������� �������� head �� �� ����� ������ ��������, ������� ������ ����� ���� ������� ��� ����� head
	}
	else {
		Node<Item>* current = head; // ���� �� �� ����� ��������� �������, ���� �� �����, � ���...
		while (current->next) {
			current = current->next; // ... ���������� �������� � ������ � �� ���������� ...
		}
		current->next = new Node<Item>(item); // ... ���������� �� ����������, ���������� � ��� next ��� ���� node
	}
	size++; // �� �������� ��� ������ ������
}

template<typename Item>
void List<Item>::push_front(Item item)
{
	this->head = new Node<Item>(item, this->head); // �������� node ����� head � ������ ���������� ��������� head, ��� ��� next ����� ��������� �� �������, ������� ��� head ������
	this->size++; // �� �������� ��� ������ ������
}

template<typename Item>
Item List<Item>::pop_front()
{
	try
	{
		if (isEmpty())
			throw length_error{ "List is empty" };
		Node<Item>* tempNode = this->head; // �������� head
		Item result = tempNode->data; // ��������� ������, ������� ��� ����
		this->head = head->next; // ������������� head �� ��������� ��� �������
		delete tempNode; // ������� ������ head
		--size; // �� �������� ��� ������ ������
		return result; // ���������� ��������, ������� ������ � ������ head
	}
	catch (const std::length_error& e)
	{
		printf("Pop_front exception caught with message: %s\n", e.what());
	}
}

template<typename Item>
Item List<Item>::pop_back()
{
	return removeAt(size - 1);
}

template<typename Item>
void List<Item>::insert(Item item, const size_t index)
{
	try
	{
		if (index > size)
			throw out_of_range{ "Index more than size of list" };

		if (index == 0) {
			push_front(item); // ���� � ������� ������ 0 �������, �� ������ ����� ���� ������� � ������
			return; // ���������� �������� ��� �� �����
		}

		size_t count = 0; // ������� ������� � ������
		for (Node<Item>* node = this->head; node; node = node->next) { // ������� ��������� ������
			count++; // ������� ������� �������������� ����, ������� �������� � �������
			if (index == count) { // ���� ���������� � ��������� ������ ����� ������ �������� � ������...
				node->next = new Node<Item>(item, node->next); // ... ��������� ���� � ������ �����
				this->size++; // �� �������� ��� ������ ������
				return; // �� ��������� ����� ���� �� �����, �� ������ �� �������� ������ �����)
			}
		}
	}
	catch (const std::out_of_range& e)
	{
		printf("Insert exception caught with message: %s\n", e.what());
	}
}

template<typename Item>
Item List<Item>::removeAt(const size_t index)
{
	try
	{
		if (isEmpty())
			throw out_of_range{ "List is empty" };
		if (index >= size)
			throw out_of_range{ "Index more than size of list" };

		if (index == 0) {
			return pop_front(); // just delete the first one element
		}

		size_t count = 0; // 
		for (Node<Item>* node = this->head; node->next; node = node->next) {
			count++;
			if (index == count) {
				// node ����� ��������� �� ���������� �������
				Node<Item>* rmElement = node->next; // ���������� �������, ������� ����� �������
				Item result = rmElement->data; // ���������� ��� ������
				node->next = rmElement->next; // ����� "�������������" �� ���������
				delete rmElement; // ��������� ��� ����� �������
				--this->size; // �� �������� ��� ������ ������
				return result; // ���� ������ �� ���� � ������������ ������ �� ��������
			}
		}
	}
	catch (const std::out_of_range& e)
	{
		printf("RemoveAt exception caught with message: %s\n", e.what());
	}
}

template<typename Item>
bool List<Item>::isEmpty() const
{
	return !(this->head); // ���� ������ ����, �� head ������ �� ����� ���������. � ������� �������������� nullptr � bool ���� false.
}

template<typename Item>
void List<Item>::clear()
{
	cout << "Clearing the list..." << endl;
	while (size) { // ��� �������� ��������� - size ����������� � ���� �� ����� ������ 0, �� �������� ����� ���������
		cout << "Deleted item: \"" << pop_front() << "\"" << endl;
	}
}

template<typename Item>
void List<Item>::print() const
{
	cout << "{ ";
	for (Node<Item>* node = this->head; node; node = node->next) {
		cout << node->data << "; ";
	}
	cout << "}" << endl;
}

template<typename Item>
size_t List<Item>::Size() const
{
	return this->size;
}

template<typename Item>
Item& List<Item>::operator[](const size_t index)
{
	try
	{
		if (index > size)
			throw out_of_range{ "Index more than size of list" };
		int count = 0; // ��� �������� ��������� � ������
		for (Node<Item>* node = this->head; node; node = node->next) { // ������� ��������� ������� � ������ � ���� �� ���������� ������ �������
			if (count == index) // ����� ���������� �� ���������� � ��������� ��������,...
				return node->data; // ... ���������� ���, ��� ���������, ��� ���� ����� ��� ����� ���� ��������
			count++; // �� �������� ��� ������� ���������
		}
	}
	catch (const out_of_range& e) // ������������ ���������� ������� ������ � ��� �����������
	{
		printf("Operator[] exception caught with message: %s\n", e.what());
	}
}
