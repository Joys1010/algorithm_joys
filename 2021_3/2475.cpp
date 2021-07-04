#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int main() {

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
	vector <int> v;
	int a,b;
	b = 0;

	for (int i=0;i<5;i++) {
		cin >> a;
		v.push_back(a);	
	}

	for (int i=0;i<5;i++) {
		b += v[i]*v[i];
	}

	cout << b%10 << endl;

	return 0;
}
