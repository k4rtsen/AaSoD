#pragma once

template<typename Item>
class List
{
public:
	List();
	~List();

	void push_back(Item);
	void push_front(Item);
	Item pop_front();
	Item pop_back();
	void insert(Item, const size_t);
	Item removeAt(const size_t);
	size_t Size() const;
	bool isEmpty() const;
	void clear();
	void print() const;

	Item& operator [](const size_t);

private:
	template<typename Item>
	struct Node {
		Item data; // сохраняем в узле списка какую-то информацию
		Node* next; // сохраняем адрес следующего элемента, чтобы была цепочка узлов (элементов) списка

		Node(Item data = Item(), Node* node = nullptr) {
			this->data = data;
			this->next = node;
		}

		~Node() {

		}
	};

	size_t size;
	Node<Item>* head;
};

template class List<int>;
