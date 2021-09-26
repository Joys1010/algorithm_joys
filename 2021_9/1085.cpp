#include <iostream>
#include <algorithm>

using namespace std;

void calculate_min(int x, int y, int w, int h) {
	int tmp = min(x, w - x);
	int tmp2 = min(y, h - y);
	
	cout << min(tmp, tmp2) << "\n";
}
int main() {

	int x, y, w, h;

	cin >> x >> y >> w >> h;

	calculate_min(x, y, w, h);

	return 0;
}
