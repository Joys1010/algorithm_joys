#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, M;
int x;
int arr[100];
int tmp, maximum;

int main() {

	FASTIO();

	cin >> N >> M;

	for (int i=0;i<N;i++) {
		cin >> x;
		arr[i] = x;
	}

	for (int i=0;i<N;i++) {
		for (int j=i+1;j<N;j++) {
			for (int k=j+1;k<N;k++) {
				tmp = arr[i]+arr[j]+arr[k];
				if (tmp > maximum && tmp <= M) {
					maximum = tmp;
				}
			}
		}
	}

	cout << maximum << "\n";


	return 0;
}
