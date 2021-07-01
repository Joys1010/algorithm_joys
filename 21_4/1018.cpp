#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;


int w,h;
int x,y;
int bw_count;
int n;
vector <int> v;
char c;
char chess[51][51];
char bw[8][8] = { {'B','W','B','W','B','W','B','W'},
		  {'W','B','W','B','W','B','W','B'},
		  {'B','W','B','W','B','W','B','W'},
		  {'W','B','W','B','W','B','W','B'},
		  {'B','W','B','W','B','W','B','W'},
		  {'W','B','W','B','W','B','W','B'},
		  {'B','W','B','W','B','W','B','W'},
		  {'W','B','W','B','W','B','W','B'} };

int main() {
	
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

	cin >> h;
	cin >> w;

	for (int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			cin >> c;
			chess[i][j] = c;
		}
	}

	for (int i=0;i<h-8+1;i++) {
		for (int j=0;j<w-8+1;j++) {
			for (int k=0;k<8;k++) {
				for (int l=0;l<8;l++) {
					if (chess[i+x][j+y] != bw[x][y]) {
						bw_count++;
					}
					y++;
				}
				y=0;
				x++;
			}
			v.push_back(bw_count);
			v.push_back(64-bw_count);
			x=0;
			y=0;
			bw_count = 0;
		}
	}

	n = v[0];
	for (int i=0;i<v.size();i++) {
		if (v[i] <= n) {
			n = v[i];
		}
	}

	cout << n << endl;

	return 0;
}
