#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calculater(int prev, int new_num, int operand) {
	int result = 0;
	if (operand == 1) {
		result = prev + new_num;
	}
	else if (operand == 2) {
		result = prev - new_num;
	}
	else if (operand == 3) {
		result = prev * new_num;
	}
	else {
		if (prev < 0) {
			result = -((-prev) / new_num);
		}
		else {
			result = prev / new_num;
		}
	}
	return result;
}

int main() {

	int num;
	int number;
	vector <int> numbers;
	int plus;
	int minus;
	int multiply;
	int divide;
	int max_value = -1000000010;
	int min_value = 1000000010;
	vector <int> calculate;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> number;
		numbers.push_back(number);
	}
	
	cin >> plus >> minus >> multiply >> divide;

	for (int i = 0; i < plus; i++) {
		calculate.push_back(1);
	}
	for (int i = 0; i < minus; i++) {
		calculate.push_back(2);
	}
	for (int i = 0; i < multiply; i++) {
		calculate.push_back(3);
	}
	for (int i = 0; i < divide; i++) {
		calculate.push_back(4);
	}
	
	do {
		int calculate_result = numbers[0];
		for (int i = 1; i < num; i++) {
			calculate_result = calculater(calculate_result, numbers[i], calculate[i - 1]);
		}
		max_value = max(calculate_result, max_value);
		min_value = min(calculate_result, min_value);
	} while (next_permutation(calculate.begin(), calculate.end()));

	
	cout << max_value << "\n" << min_value << "\n";

	return 0;
}

