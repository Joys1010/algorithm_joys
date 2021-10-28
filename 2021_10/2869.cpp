#include <iostream>

using namespace std;

int A, B, V;

int main() {
	
	cin >> A >> B >> V;

	int cnt = 0;
	int now = 0;
	
	if ((V - A) % (A - B) == 0) {
		cnt = (V - A) / (A - B) + 1;
	}
	else {
		cnt = (V - A) / (A - B) + 2;
	}
	cout << cnt << "\n";
	return 0;
}

