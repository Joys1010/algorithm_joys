#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, x;
int numbers[10010];
int main() {

	FASTIO();

	cin >> N;
	//scanf("%d\n",&N);

	for (int i=0;i<N;i++) {
		cin >> x;
		//scanf("%d\n",&x);
		numbers[x]++;
	}	

	for (int i=0;i<10010;i++) {
		if (numbers[i] != 0) {
			for (int j=0;j<numbers[i];j++) {
				cout << i << "\n";
				//printf("%d\n",i);
			}
		}
	}
	return 0;
}
