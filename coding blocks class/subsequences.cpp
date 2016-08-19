#include <iostream>
using namespace std;

// returns number of rows in the output, takes input string and the output 2d array
int subs(char input[], char output[][100]) {
	if (input[0] == '\0') {
		output[0][0] = '\0';
		return 1;
	}

	int smallerOutputRows = subs(input + 1, output);
	for (int i =0; i < smallerOutputRows; i++) {
		output[i + smallerOutputRows][0] = input[0];
		int j;
		for (j = 0; output[i][j] != '\0'; j++) {
			 output[i + smallerOutputRows][j + 1] =
				 output[i][j];
		}
		output[i + smallerOutputRows][j + 1] = '\0';
	}
	return 2*smallerOutputRows;
}

int main() {
	char input[20];
	cin >> input;
	char output[1000][100];
	int rows = subs(input, output);

	for (int i = 0; i < rows; i++) {
		cout << output[i] << endl;
	}


}


