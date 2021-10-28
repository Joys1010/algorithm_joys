#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int r = 31;
int M = 1234567891;

int l;
string s;
unsigned long long ans;
unsigned long long mul = 1;

int main() {
	
	cin >> l;
	cin >> s;

	for (int i = 0; i < l; i++) {
		int tmp = s[i] - '0' - 48;
		tmp = (tmp * mul % M);
		ans += (tmp % M);
		ans %= M;
		mul = mul * r % M;
	}
	
	cout << ans;

	return 0;
}

