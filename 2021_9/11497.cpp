#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int T, N;
int x;
int level;

int main() {
	FASTIO();
	
	cin >> T;

	while (T > 0) {
		
		cin >> N;
		vector <int> numbers; 
		vector <int> answer(N,0);
		for (int i = 0; i < N; i ++) {
			cin >> x;
			numbers.push_back(x);
		}
	
		sort(numbers.begin(), numbers.end());
	
		if (N % 2 == 0) {
			int num_pos = 0;
			for (int i = 0; i < N/2; i ++) {
				answer[i] = numbers[num_pos];
				answer[N-1-i] = numbers[num_pos+1];
				num_pos += 2;
			}

			level = answer[N-1] - answer[0];
			if (level < 0) {
				level = (-1)*level;
			}	
				
			for (int i = 0; i < N-1; i ++) {
				int tmp = answer[i] - answer[i+1];
				if (tmp < 0) {
					tmp = (-1)*tmp;
				}
				
				if (tmp > level) {
					level = tmp;
				}
			}
		}
			
		else {
			int num_pos = 0;
			for (int i = 0; i < N/2; i ++) {
				answer[i] = numbers[num_pos];
				answer[N-1-i] = numbers[num_pos+1];
				num_pos += 2;	
			};
			answer[N/2] = numbers[num_pos];

			level = answer[N-1] - answer[0];
			if (level < 0) {
				level = (-1)*level;
			}
			for (int i = 0; i < N-1; i ++) {
				int tmp = answer[i] - answer[i+1];
				if (tmp < 0) {
					tmp = (-1)*tmp;
				}

				if (tmp > level) {
					level = tmp;
				}	
			}
			
		}
			
		cout << level << "\n";
		T--;
	}

	return 0;
}	
