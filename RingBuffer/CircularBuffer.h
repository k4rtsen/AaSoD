#include <array>
#pragma once

template<typename Item, size_t N>
class CircularBuffer
{
public:
	CircularBuffer() :
		write{0},
		read{0}
	{
		buffer.fill(Item());
	}

	// copy constructor is default
	// move constructor is default

	~CircularBuffer() = default;

	size_t getSize() {
		return N;
	}

	void Write(const Item item) {
		buffer[write] = item;
		write = (write + 1) % N; // write++; reset if write = N
	}

	Item Read() {
		Item result = buffer[read];
		read = (read + 1) % N; // read++; reset if read = N
		return result;
	}

private:
	size_t write;
	size_t read;
	std::array<Item, N> buffer;
};
