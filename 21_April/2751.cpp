#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 2000010

using namespace std;

int n, m;
int arr[MAX_NUM] = {0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		
		arr[m + 1000000] = 1;

	}

	for (int i = 0; i < MAX_NUM; i++) {

		if (arr[i] == 1) {
			cout << (i - 1000000) << "\n";
		}
	}

	return 0;
}
