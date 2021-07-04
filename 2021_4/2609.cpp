#include <iostream>
#include <queue>
using namespace std;

int n, m, gcd, lcm;
int r, r1, r2;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> m;

	r1 = n;
	r2 = m;

	//gcd
	while (r2 > 0) {
		r = r1%r2;
		r1 = r2;
		r2 = r;
	}
	gcd = r1;

	//lcm
	lcm = n * m / gcd;

	cout << gcd << endl;
	cout << lcm;


	return 0;
}
