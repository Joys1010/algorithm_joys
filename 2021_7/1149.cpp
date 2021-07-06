#include <iostream>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int value[1010][3];
int dps[1010][3];
int mini, tmp;
void dp_zero() {
	
	dps[0][0] = value[0][0];
	dps[0][1] = value[0][1];
	dps[0][2] = value[0][2];
}

void dp(int x) {

	for (int i=0;i<3;i++) {
		
		dps[x][i] = value[x][i]+ min(dps[x-1][(i+1)%3], dps[x-1][(i+2)%3]);
	}	

}
int main() {
	FASTIO();

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> value[i][0] >> value[i][1] >> value[i][2];
	}

	dp_zero();

	for (int i=1;i<N;i++) {
		dp(i);
	}

	mini = dps[N-1][0];

	for (int i=0;i<3;i++) {
		
		tmp = dps[N-1][i];
		if (tmp < mini) {
			mini = tmp;
		}	
	}
	cout << mini << "\n";

	return 0;
}
