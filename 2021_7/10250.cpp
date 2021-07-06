#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int T;
int H, W, N;
int result;
int floors, room;

int main() {
	FASTIO();

	cin >> T;

	while (T>0) {
		result = 0;

		cin >> H >> W >> N;
		
		floors = N%H;
		room = N/H;

		if (floors == 0) {
			result = H*100+room;
		}
		else {
			result = floors*100 + room + 1;
		}
	       		
		cout << result << "\n";
		
		T--;
	}
	return 0;
}
