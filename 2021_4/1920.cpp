#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, t, flg;
int l, r, mid, midVal;
vector <int> v;

int main() {
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(),v.end());

	cin >> k;

	for (int i=0; i<k; i++) {

		cin >> t;
		
		l = 0;
		r = n-1;
		flg = 0;

		//binary search
		while (l <= r) {
			mid = (l+r)/2;
			midVal = v[mid];

			if (midVal > t) {
				r = mid-1;
			}
			else if (midVal < t) {
				l = mid+1;
			}
			else if (midVal == t) {
				//find!
				cout << "1\n";
				flg = 1;
				break;
			}
		}
		if (flg == 0) {
			cout << "0\n";
		}
	}
	return 0;
}


