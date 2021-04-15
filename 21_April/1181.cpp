#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

bool strsort(string i, string j) {

	int iSize = i.size();
	int jSize = j.size();

	if (iSize == jSize) {
		return i < j;
	}
	else {
		return iSize < jSize;
	}


}

int n,a,b;
string m;
vector <string> v;

int main() {
	
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for (int i=0;i<n;i++) {
		cin >> m;
		v.push_back(m);
	}
	
	sort(v.begin(),v.end(),strsort);

	v.erase(unique(v.begin(),v.end()),v.end());

	a = v.size();

	for (int i=0;i<a;i++) {

		cout << v[i] << endl;
	}

	return 0;
}
