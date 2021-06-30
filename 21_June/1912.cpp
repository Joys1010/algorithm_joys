#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
int arr[100010];
int localMax;
int globalMax;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i=0;i<n;i++) {
		cin >> x;
		arr[i] = x;	
	}

	localMax = arr[0];
	globalMax = arr[0];

	for (int i=1;i<n;i++) {

		localMax = max(arr[i], localMax + arr[i]);
		if (globalMax < localMax) {
			globalMax = localMax;
		}
	}

	cout << globalMax << endl;
	
	return 0;
}
