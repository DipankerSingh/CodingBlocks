#include <iostream>
#include <cstring>
using namespace std;

class Student {
	private:
	int rollNumber;

	public:
	char* name;

	Student() {
		cout << "Student constructor called" << endl;
		name = new char[1];
	}

	Student(Student const & s):rollNumber(s.rollNumber) {
		cout << "copy constructor called" << endl;
		name = new char[strlen(s.name) + 1];
		strcpy(name, s.name);
	}

	Student(int roll, char* name):rollNumber(roll) {
		cout << "custom constructor called" << endl;
		name = new char[strlen(name) + 1];
		strcpy((*this).name, name);
	}

	int getRollNumber() const {
		return rollNumber;
	}

	void setName(char* n) {
		delete name;
		name = new char[strlen(n) + 1];
 		strcpy(name, n);
	}
	char* getName() const{
		return name;
	}


	Student operator++ (int) {
		Student s(rollNumber, name);
		(*this).rollNumber++;
		return s;
	}

	Student operator= (const Student & s2) {
		name = new char[strlen(s2.name) + 1];
		strcpy(name, s2.name);
		return *this;
	}

	bool operator< (const Student & s2) const{
		if (rollNumber < s2.rollNumber) {
			return true;
		}
		return false;
	}


	~Student() {
		cout << "Destructor called" << endl;
		delete name;
	}
};

/*
int main() {

	int i = 10;
	int j = 20;
	++(i = j);

	cout << i << endl;
	cout << j << endl;


	char n1[] = "Singla";	
	Student s(100, n1);
	Student s1(s);
	Student s4 = s;
	
	const Student s5(101, n1);
	s5.getName();
	s5.getRollNumber();
	cout << (s < s5) << endl;


	char n1[] = "Singla";
	Student s(1000, n1);
	Student s2(s);
	
	Student s3;
	s3 = s;
	cout << s.name << endl;
	cout << s2.name << endl;
	s.name[0] = 's';
	cout << s.name << endl;
	cout << s2.name << endl;
		char n1[] = "Singla";
	Student s(1000, n1);
	cout << s.getRollNumber() << endl;
	s.setRollNumber(10);
	cout << s.getRollNumber() << endl;
	char n[] = "Ankush";
	Student* s1 = new Student(100, n);
  Student s2(*s1);
	cout << (*s1).getRollNumber() << endl;
	cout << (*s1).getName() << endl;
	Student s2(s);
	s2 = s;
	delete s1;
}*/
