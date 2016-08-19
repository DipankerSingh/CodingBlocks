#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.top();
	
	vector<int> v;
	v.push_back(10);
	v.pop_back();


}
