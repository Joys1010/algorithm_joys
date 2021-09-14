#include <iostream>
#include <vector>
#include <utility>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, num;
bool status;
int gender, pos;
int sym;
bool switchs[101];

vector <pair<int,int>> info;

void change_switch(int gender, int pos);

int main() {
	FASTIO();

	cin >> N;
	
	for (int i = 1; i <= N; i ++) {
		cin >> switchs[i];		
	}

	cin >> num;	

	for (int i = 0; i < num; i ++) {
		cin >> gender >> pos;
		
		info.push_back({gender, pos});
	}

	for (int i = 0; i < info.size(); i ++) {
		
		change_switch(info[i].first, info[i].second);
	}

	for (int i = 1; i <= N; i ++) {
		cout << switchs[i] << " ";
		if (i%20 == 0) {
			cout << "\n";
		}	
	}
	
	return 0;
}

void change_switch(int gender, int pos) {
	
	if (gender == 1) {
		for (int i = 1; i <= N; i++) {
			if (i % pos == 0) {
				switchs[i] = !switchs[i];
			}
		}
	}
	else {

		sym = 1;
		while (true) {
			if (pos+sym <= N && pos-sym >=1) {
				if (switchs[pos+sym] == switchs[pos-sym]) {
					sym++;
				}
				else {

					break;

				}
			}
			else {
				break;
			}
		}
		sym = sym - 1;
		for (int i = pos-sym; i <= pos+sym; i++) {
			switchs[i] = !switchs[i];
		}
	}
}
