#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N,M;
int x;
int arr[20000010];

int main() {

	FASTIO();

	cin >> N;
	for (int i=0;i<N;i++) {
		cin >> x;
		arr[x+10000000]++;
	}

	cin >> M;
	for (int i=0;i<M;i++) {
		cin >> x;
		cout << arr[x+10000000] << " ";
	}

	return 0;
}
