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
		head = new Node<Item>(item); // в next несуществующего элемента head мы не можем ничего записать, поэтому первым делом надо создать тот самый head
	}
	else {
		Node<Item>* current = head; // если бы мы знали последний элемент, было бы проще, а так...
		while (current->next) {
			current = current->next; // ... перебираем элементы с начала и до последнего ...
		}
		current->next = new Node<Item>(item); // ... добравшись до последнего, записываем в его next еще один node
	}
	size++; // не забываем про размер списка
}

template<typename Item>
void List<Item>::push_front(Item item)
{
	this->head = new Node<Item>(item, this->head); // поставим node перед head и просто передвинем указатель head, при том next будет указывать на элемент, который был head раньше
	this->size++; // не забываем про размер списка
}

template<typename Item>
Item List<Item>::pop_front()
{
	try
	{
		if (isEmpty())
			throw length_error{ "List is empty" };
		Node<Item>* tempNode = this->head; // забираем head
		Item result = tempNode->data; // сохраняем данные, которые там были
		this->head = head->next; // переназначаем head на следующий его элемент
		delete tempNode; // очищаем старый head
		--size; // не забываем про размер списка
		return result; // возвращаем значение, которое лежало в старом head
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
			push_front(item); // если в индексе указан 0 элемент, то просто пушим этот элемент в начало
			return; // дальнейшие действия нам не нужны
		}

		size_t count = 0; // подсчет индекса в списке
		for (Node<Item>* node = this->head; node; node = node->next) { // перебор элементов списка
			count++; // нулевой элемент обрабатывается выше, поэтому начинаем с первого
			if (index == count) { // если переданный в аргументе индекс равен номеру элемента в списке...
				node->next = new Node<Item>(item, node->next); // ... вставляем узел в данное место
				this->size++; // не забываем про размер списка
				return; // не позволяем циклу идти до конца, не всегда же получать худшее время)
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
				// node будет указывать на предыдущий элемент
				Node<Item>* rmElement = node->next; // запоминаем элемент, который нужно удалить
				Item result = rmElement->data; // запоминаем его данные
				node->next = rmElement->next; // адрес "перепрыгивает" на следующий
				delete rmElement; // удаляется тот самый элемент
				--this->size; // не забываем про размер списка
				return result; // цикл дальше не идет и возвращаются данные из элемента
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
	return !(this->head); // если список пуст, то head никуда не будет указывать. А неявное преобразование nullptr в bool даст false.
}

template<typename Item>
void List<Item>::clear()
{
	cout << "Clearing the list..." << endl;
	while (size) { // при удалении элементов - size уменьшается и пока не будет равным 0, то элементы будут удаляться
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
		int count = 0; // для подсчета элементов в списке
		for (Node<Item>* node = this->head; node; node = node->next) { // перебор элементов начиная с головы и пока не встретится пустой элемент
			if (count == index) // когда добираемся до указанного в аргументе элемента,...
				return node->data; // ... возвращаем его, как указатель, для того чтобы его можно было изменять
			count++; // не забываем про подсчет элементов
		}
	}
	catch (const out_of_range& e) // обрабатывает исключения данного класса и его наследников
	{
		printf("Operator[] exception caught with message: %s\n", e.what());
	}
}
