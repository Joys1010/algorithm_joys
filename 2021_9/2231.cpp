#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int N;

	cin >> N;
    
	for (int i = 0; i < N; i++) {
		int ans = i;
		string tmp_i = to_string(i);
		for (int j = 0; j < tmp_i.size(); j++) {
			ans += (tmp_i[j] - '0');
		}
		if (ans == N) {
			cout << i << "\n";
			return 0;
		}
	}
    
	cout << "0\n";
    
	return 0;
}
