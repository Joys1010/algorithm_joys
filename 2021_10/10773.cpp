#include <iostream>
#include <vector>

using namespace std;

int K;
int num;
int answer;
vector <int> numbers;

int main() {
	
	cin >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num != 0) {
			numbers.push_back(num);
		}
		else {
			numbers.pop_back();
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}

	cout << answer << "\n";

	return 0;
}

