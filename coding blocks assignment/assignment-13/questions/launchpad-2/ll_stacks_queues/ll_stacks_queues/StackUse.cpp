#include <iostream>
#include "Stack.h"
using namespace std;

bool brackets_balanced(char input[]) {
	Stack<int> s(100);
	for (int i = 0; input[i] != '\0'; i++) {
		char c = input[i];
		if (c == '(' || c == '{' || c == '[') {
			s.push(c);
		} else if (c == ')') {
			if (s.pop() != '(') {
				return false;
			}
		} else if (c == '}') {
			if (s.pop() != '{') {
				return false;
			}
		} else if (c == ']') {
			if (s.pop() != '[') {
				return false;
			}
		}
	}
	if (s.is_empty()) {
		return true;
	} else {
		return false;
	}
}

int main() {
	char n[] = " { a + [ b+ (c + d)] + (e + f) }}";
	cout <<brackets_balanced(n) << endl;
	Stack<int> s(10);
	int a[] = {1,2,3,4,5,6};
	for (int i = 0; i < 6; i++) {
		s.push(a[i]);
	}

	while (!s.is_empty()) {
		cout << s.pop() << endl;
	}

}
