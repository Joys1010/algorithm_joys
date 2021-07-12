#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int numbers[1000001];
int lis[1000001];
int lis_cnt;
vector <int> tracing;
vector <int> tmp_lis;
void find_lis() {

	for (int i=0;i<N;i++) {
		if (i == 0 || numbers[i] > lis[lis_cnt-1]) {
			lis[lis_cnt++] = numbers[i];
			tracing.push_back(lis_cnt);
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
			tracing.push_back(idx+1);
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

	int pos = lis_cnt;
	int tracing_cnt = tracing.size();
	for (int i=tracing_cnt -1;i>-1;i--) {
		if (tracing[i] == pos) {
			tmp_lis.push_back(numbers[i]);
			pos--;
		}
	}

	int final_cnt = tmp_lis.size();
	for (int i=0;i<final_cnt;i++) {
		lis[lis_cnt-1-i] = tmp_lis[i];
	}

	cout << lis_cnt << "\n";
	for (int i=0;i<lis_cnt;i++) {
		cout << lis[i]<< " ";
	}
	
	
	return 0;
}
