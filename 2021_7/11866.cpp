#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int people[1010];
vector <int> result;
int N, K, cnt, check;

int main() {


	cin >> N >> K;

	check = N;
	for (int i=1;i<N+1;i++) {
		people[i] = 1;	
	}

	while (check > 0) {
		for (int i=1;i<N+1;i++) {
			if (people[i] != 0) {
				cnt++;
			}
			if (cnt == K) {
				people[i] = 0;
				result.push_back(i);
				check--;
				cnt = 0;
			}	
		}

	}
	
	int size = result.size();

	cout << "<";
	for (int i=0;i<size;i++) {
		
		cout<< result[i];

		if (i != size-1) {
			cout << ", ";
		}
		else {
			cout << ">\n";
		}
	}
	return 0;
}
