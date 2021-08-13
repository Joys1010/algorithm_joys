#include <iostream>
#include <string>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int answer;

int find(string n) {

	if ( n.find("666") == string::npos) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	FASTIO();
	
	cin >> N;
	int result = 0;
	
	string num = "665";	

	while (N > 0) {
		
		num = to_string((stoi(num) + 1));
		result = find(num);

		if (result == 1) {
			N--;
		}
	}
	
	cout << num << "\n";
	
	return 0;
}
