#include <iostream>
using namespace std;

void largest_unique_substring(char str[]);

int main() {
	char a[30];
	cin >> a;
	largest_unique_substring(a);
}

void largest_unique_substring(char str[]) {

	int current_substring_start = 0;
	int largest_string_start = 0;
	int largest_string_end = 0;

	int last_index[256];
	for (int i = 0; i < 256; i++) {
		last_index[i] = -1;
	}
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		char current = str[i];
		int last = last_index[current];
		if (last >= current_substring_start) {
			int best_length =
				largest_string_end - largest_string_start + 1;
			int current_length = i - 1 - current_substring_start + 1;
			if (current_length > best_length) {
				largest_string_start = current_substring_start;
				largest_string_end = i -1;
			}
			current_substring_start = last + 1;
		}
		last_index[current] = i;
	}

			int best_length =
				largest_string_end - largest_string_start + 1;
			int current_length = i - 1 - current_substring_start + 1;
			if (current_length > best_length) {
				largest_string_start = current_substring_start;
				largest_string_end = i -1;
			}


	str[largest_string_end + 1] = '\0';
	cout << str + largest_string_start << endl;
}

