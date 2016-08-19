#ifndef STACK_H
#define STACK_H 1
template <typename T>
class Stack {
	int size;
	T* data;

	public:
	Stack(int n) {
		size = 0;
		data = new T[n];
	}

	~Stack() {
		delete[] data;
	}

	int get_size() {
		return size;
	}

	bool is_empty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	T top() {
		if (is_empty()) {
			return -1;
		}
		return data[size - 1];
	}

	void push(T newElement) {
		if (size == 50) {
			return;
		}
		data[size] = newElement;
		size++;
	}

	T pop() {
		if (is_empty()) {
			return -1;
		}
		T to_be_returned = data[size - 1];
		//data[size - 1] = 0;
		size--;
		return to_be_returned;
	}
};
#endif
