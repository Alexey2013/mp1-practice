#ifndef _CONTAINER_H
#define _CONTAINER_H
using namespace std;

template <typename T> class Container {
protected:
	T* elements;
	int currentIndex;
	int size;
	int capacity;
	int step;
	void resize() {
		T* newElements = new T[capacity + step];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}
		delete[] elements;
		elements = newElements;
		capacity += step;
	}
public:
	Container() :
		step(5), size(0), capacity(0), currentIndex(0), elements(new T[capacity])
	{
	}
	Container(int capacity, int step = 5) :
		capacity(capacity), step(step), elements(new T[capacity]), size(0), currentIndex(0)
	{
	}
	~Container() {
		delete[] elements;
	}

	void add(const T& element) {
		if (size == capacity) {
			resize();
		}
		elements[size] = element;
		size++;
	}
	void remove(const T& element) {
		int i;
		for (i = 0; i < size; i++) {
			if (elements[i] == element)
				break;
		}
		for (i; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}
	void remove(int index) {
		if (index >= size || index < 0) { return; }
		for (int i = index; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}
	int getSize() const { return size; }
	T& operator[](int index) { return elements[index]; }

	bool isEnd() {
		return currentIndex == size - 1;
	}
	void next() {
		if (isEnd() || size == 0)
			return;
		currentIndex++;
	}
	void prev() {
		if (currentIndex == 0)
			return;
		currentIndex--;
	}
	T getCurrent() {
		if (size == 0)
			return -1;
		return elements[currentIndex];
	}
	void reset() {
		currentIndex = 0;
	}
};

#endif 