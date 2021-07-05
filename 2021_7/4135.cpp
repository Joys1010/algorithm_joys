#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int x,y,z;

void print(int x, int y, int z) {
	
	if (y*y + z*z == x*x) {
		cout << "right\n";
	}
	else {
		cout << "wrong\n";
	}
}

int main() {

	cin >> x >> y >> z;

	while (x!= 0) {
	
		if (x > y && x > z) {
			print(x,y,z);	
		}
		else if (y > x && y > z) {
			print(y,x,z);
		}
		else if (z > x && z > y) {
			print(z,x,y);
		}

		cin >> x >> y >> z;
	}

	return 0;
}
