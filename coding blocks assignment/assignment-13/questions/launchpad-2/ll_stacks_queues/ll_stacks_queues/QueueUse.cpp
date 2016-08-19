#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue q;
	for (int i = 0; i < 60; i++) {
		q.enqueue(i);
	}

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.enqueue(7);
	q.enqueue(8);

	while (!q.is_empty()) {
		cout << q.dequeue() << endl;
	}

}

