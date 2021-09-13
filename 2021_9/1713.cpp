#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int recommand_num;
int recommanded_person;
int filled;

typedef struct Person {

	int person_num;
	int time;
	int like_num;
} person;


bool cmp(person a, person b) {
	
	if (a.like_num == b.like_num) {
		return a.time > b.time;
	}

	return a.like_num > b.like_num;
}

bool cmp2(person a, person b) {
	return a.person_num < b.person_num;
}

int main() {
	FASTIO();

	cin >> N;

	vector <person> information;

	cin >> recommand_num;
	
	for (int i = 0; i < recommand_num; i ++) {
		
		cin >> recommanded_person;
		filled = information.size();
		
		int flg = 0;
		for (int j = 0; j < filled; j ++) {
			if (information[j].person_num == recommanded_person) {
				information[j].like_num++;
				flg = 1;
			}
		}

		if (flg == 0) { 
			if (filled == N) {
				sort(information.begin(), information.end(), cmp);
				
				person new_p;
				new_p.person_num = recommanded_person;
				new_p.time = i;
				new_p.like_num = 1;
				
				information[filled-1] = new_p;

			}
			else {
				person new_p;
				new_p.person_num = recommanded_person;
				new_p.time = i;
				new_p.like_num = 1;
				
				information.push_back(new_p);
			}
		}
	}

	sort(information.begin(), information.end(), cmp2);

	filled = information.size();
	for (int i = 0; i < filled; i ++) {
		cout << information[i].person_num << " ";
	}	

	return 0;
}
