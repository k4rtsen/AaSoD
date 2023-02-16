#include <iostream>
#include "CircularBuffer.h"
using namespace std;

template<typename Item>
class RingBuffer
{
public:
	RingBuffer(const size_t capacity) :
		size { capacity }
	{
		this->tail = new Node<Item>();
		this->head = this->tail;

		for (size_t i = 0; i < size - 1; i++) // first item was created, so (size - 1)
		{
			// created N nodes
			Node<Item>* temp = head;
			this->head = new Node<Item>();
			this->head->next = temp;
		}
		this->tail->next = head; // loop the buffer
		this->p_write = head;
		this->p_read = head;
	}

	// copy constructor is default
	// move constructor is default

	~RingBuffer() {
		auto cleaning = [&]() {
			// delete first element in buffer
			Node<Item>* temp = this->head;
			this->head = this->head->next;
			delete temp;
		};
		this->p_read = this->tail;
		this->p_write = this->tail;
		while (head != tail) {
			cleaning();
		}
		delete this->tail;
		this->tail = nullptr;
		this->head = nullptr;
		this->p_read = nullptr;
		this->p_write = nullptr;
	}

	void Write(const Item& item) noexcept {
		p_write->data = item;
		p_write = p_write->next;
	}

	Item Read() noexcept {
		Item result = p_read->data;
		p_read = p_read->next;
		return result;
	}

	size_t getSize() const { 
		return this->size; 
	}

private:
	template<typename Item>
	struct Node {
		Item data;
		Node* next;

		Node(Item data = Item(), Node* node = nullptr) {
			this->data = data;
			this->next = node;
		}

		~Node() = default;
	};

	size_t size;
	Node<Item>* head;
	Node<Item>* tail;
	Node<Item>* p_read;
	Node<Item>* p_write;
};

int main() {
	const size_t N = 10;
	CircularBuffer<int, N> rb;
	for (int i = 0; i < N; i++)
	{
		rb.Write(i + 1);
	}
	for (size_t i = 0; i < N; i++)
	{
		cout << rb.Read() << "; ";
	}
	rb.Write(99);
	rb.Write(98);
	rb.Write(97);
	cout << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << rb.Read() << "; ";
	}
}
