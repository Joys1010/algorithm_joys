#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int n,m,mini,maxi;
int sum;
int sum_mini;
vector <int> v;
vector <int> pro;
vector <pair <int,int>> r;
int main() {
	
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for (int i=0;i<n;i++) {
		cin >> m;
		v.push_back(m);
	}
	
	sort(v.begin(),v.end());


	if (n%2 == 0) {
		cout << v[(n/2)-1] << endl;
	}
	else {
		cout << v[n/2] << endl;
	}

	return 0;
}
