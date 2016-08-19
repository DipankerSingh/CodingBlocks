#ifndef QUEUE_H
#define QUEUE_H 1
class Queue {
	int* data;
	int firstIndex;
	int nextIndex;
	int size;
  int capacity;

	public:
	Queue() {
		capacity = 5;
		data = new int[capacity];
		firstIndex = -1;
		nextIndex = 0;
		size = 0;
	}

	~Queue() {
		delete [] data;
	}

	int front() {
		if (size == 0) {
			return -1;
		}
		return data[firstIndex];
	}

	int dequeue() {
		if (size == 0) {
			return -1;
		}
		
		int to_be_returned = data[firstIndex];
		data[firstIndex] = 0;
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if (size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return to_be_returned;
	}

	void enqueue(int element) {
		if (firstIndex == -1) {
			firstIndex = 0;
		} 
		if (size == capacity) {
			int* temp = data;
			data = new int[2*capacity];
			int k = 0;
			for (int i = 0; i < capacity; i++) {
				int fromIndex = (firstIndex + i) % capacity;
				data[k] = temp[fromIndex];
				k++;
			}
			capacity = 2*capacity;
			firstIndex = 0;
			nextIndex = k;
			delete [] temp;
		}
		data[nextIndex] = element;
		size++;
		nextIndex = (nextIndex + 1) % capacity;
	}

	int get_size() {
		return size;
	}

	bool is_empty() {
		return (size == 0);
	}


};
#endif
