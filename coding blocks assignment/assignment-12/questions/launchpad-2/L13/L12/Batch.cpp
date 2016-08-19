#include "Student.cpp"

class Batch {
	int num_students;
	Batch* cr;

	public:
	Batch() {
		cr = 0;
		num_students = 10;
		cout << "Batch constructor called";
	}
};

int main() {
	Batch b;
}
