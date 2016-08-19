#ifndef STACK_H
#define STACK_H 1
template <typename T>
class Stack {
	int size;
	int *data;


	public:
	Stack(){
		size = 0;
		data = new int[50];
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

	int top() {
		if (is_empty()) {
			return -1;
		}
		return data[size - 1];
	}

	void push(int newElement) {
		if (size == 50) {
			return;
		}
		data[size] = newElement;
		size++;
	}

	int pop() {
		if (is_empty()) {
			return -1;
		}
		int to_be_returned = data[size - 1];
		data[size - 1] = 0;
		size--;
		return to_be_returned;
	}
};
#endif
