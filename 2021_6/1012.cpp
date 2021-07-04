#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int m,n;
int k;
int x,y;
int result;
int v[52][52];

void dfs(int x,int y) {
		
	v[x][y] = 0;

	for (int i=-1;i<2;i++) {
		for (int j=-1;j<2;j++) {

			int now_i = x+i;
			int now_j = y+j;

			if (i+j == -1 || i+j == 1) {
				if (0<= now_i && now_i < m && 0<= now_j && now_j < n && v[now_i][now_j] == 1) {
					dfs(now_i,now_j);
				}
			}
		}
	}	
	return;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> t;


	while (t>0) {
		cin >> m;
		cin >> n;
		cin >> k;

		for (int i=0;i<k;i++) {
			cin >> x;
			cin >> y;
			v[x][y] = 1;
		}

		if (k == 1) {
			result = 1;
		}
		else {
			result = 0;
			for (int i=0;i<m;i++) {
				for (int j=0;j<n;j++) {
					if (v[i][j] == 1) {
						dfs(i,j);
						result++;
					}
				}
			}	
		}
		cout << result << "\n";
		t--;
	}
	
	return 0;
}
