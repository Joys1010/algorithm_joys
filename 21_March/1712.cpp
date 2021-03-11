#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int main() {

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

	int a,b,c;

	cin >> a;
	cin >> b;
	cin >> c;

	if (c-b <= 0) {
		cout << "-1" << endl;
	}
	else {
		cout << a/(c-b)+1 << endl;
	}		

	return 0;
}
