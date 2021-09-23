#include <iostream>

using namespace std;

#define MAX_N 1000000

int N;
int president, vice_president;
int rooms[MAX_N];
long long answer;

int main() {

    cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> rooms[i];
	}

	cin >> president >> vice_president;

	for (int i = 0; i < N; i++) {
        answer++;
		rooms[i] -= president;

		if (rooms[i] < 1) {
			continue;
		}
			
		if (rooms[i] % vice_president != 0) {
			answer = answer + (rooms[i] / vice_president) + 1;
		}
		else {
			answer = answer + rooms[i] / vice_president;
		}
	}

	cout << answer << "\n";
	return 0;
}

