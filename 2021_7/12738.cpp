#include <iostream>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int numbers[1000001];
int lis[1000001];
int lis_cnt;

void find_lis() {

	for (int i=0;i<N;i++) {
		if (i==0 || numbers[i] > lis[lis_cnt-1]) {
			lis[lis_cnt++] = numbers[i];
		}
		else {
			int start = 0;
			int end = lis_cnt;
			int idx = lis_cnt;
			while (start < end) {
				int mid = (start+end)/2;
				if (lis[mid] >= numbers[i]) {
					idx = min(idx, mid);
				       	end = mid;	
				}
				else {
					start = mid+1;
				}
			}
			lis[idx] = numbers[i];
		}
	}
}
int main() {
	FASTIO();

	cin >> N;
	
	for (int i=0;i<N;i++) {
		cin >> numbers[i];
	}

	find_lis();

	cout << lis_cnt << endl;
	
	return 0;
}
