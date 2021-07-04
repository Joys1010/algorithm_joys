#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int a,total,t,c;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> a;

	total = 1;
	c = 0;
	t = 1;

	if (a == 1) {
		c = 1;
	}

	while (1) {
		if (total >= a) {
			break;
		}
		t = 6 * c;
		c++;
		total += t;
	}

	cout << c << endl;

	return 0;	
}
