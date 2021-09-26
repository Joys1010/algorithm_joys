#include <iostream>

using namespace std;

int main() {
	
	int kg;
	int cnt = 0;

	cin >> kg;
	for (int i = 0; i < 4; i++) {
		if (kg % 5 == 0) {
			break;
		}
		kg -= 3;
		cnt++;
	}
	
	if (kg % 5 != 0 || kg < 0) {
		cnt = -1;
	}
	else
		cnt += kg / 5;
	cout << cnt << "\n";

	return 0;
}
