#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int d;
vector<vector<int>> v(52,vector<int>(52));
int maximum;
int tmp;
int r;
char c;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> m;

	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin >> c;
			d = c - '0';
			v[i][j] = d;
		}
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			for (int k=j;k<m;k++) {
				if (v[i][j] == v[i][k]) {
					r = k - j;
					if (i+r < n) {
						if (v[i][j] == v[i+r][j] && v[i][j] == v[i+r][k]) {
							tmp = (r+1)*(r+1);
							if (maximum < tmp) {
								maximum = tmp;
							}
						}

					}

				}
			}
		}
	}
	cout << maximum << endl;
	return 0;
}

