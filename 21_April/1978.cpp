#include <iostream>
#include <vector>
#define MAX_NUM 100

using namespace std;
int n, m, cnt;
bool b;
vector <int> v(MAX_NUM);

bool prime(int num);

int main() {

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> m;
		v[i] = m;
	}

	for (int i=0; i<n; i++) {
		if (v[i] == 1) {
			continue;
		}
		b = prime(v[i]);
		if (b == true) {
			cnt++;
		}	
	}

	cout << cnt;
	return 0;
}

bool prime(int num) {

	for (int i=2;i<num;i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

