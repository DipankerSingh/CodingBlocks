#include <iostream>
using namespace std;
class mypair {
	int i;
	int j;
	public:
	mypair() {
		cout << "constructor called" << endl;
	}

	~mypair() {
		cout << "destructor called" << endl;
	}

	mypair(mypair &c) {
		cout << "copy constructor called" << endl;
	}

	mypair& operator=(mypair const &c) {
		cout << "copy assignment operator" << endl;
		return *this;
	}

};

mypair temp() {
	mypair p1;
	return p1;
}

int main() {
	mypair p;
	p = temp();
}












