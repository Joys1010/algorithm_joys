#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, M;

int map[51][51];
bool cloud[51][51];
int speed;
int direction;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
vector <pair<int, int>> increased_basket;

void move_and_rain();
void copy_water();
void new_cloud();



int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//first cloud
	cloud[N - 1][0] = true; //(N,1)
	cloud[N - 1][1] = true; //(N,2)
	cloud[N - 2][0] = true; //(N-1,1)
	cloud[N - 2][1] = true; //(N-2,2)

	for (int i = 0; i < M; i++) {

		cin >> direction;
		cin >> speed;

		direction = direction - 1; //for easy calculation


		move_and_rain(); //step 1 and 2

		copy_water(); //step 4

		new_cloud(); //step 5 with step 3
	
	}

	

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += map[i][j];
		}
	}

	cout << ans << "\n";

	return 0;
}
  
void move_and_rain() {
	
	bool new_cloud_map[51][51] = { false, };
	
	increased_basket.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cloud[i][j] == true) { //there is cloud
				speed = speed % N;
				//real move
				int new_r = (i + speed * dy[direction] + N) % N;
				int new_c = (j + speed * dx[direction] + N) % N;
				new_cloud_map[new_r][new_c] = true;

				//rain
				map[new_r][new_c]++;
				increased_basket.push_back({ new_r, new_c });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cloud[i][j] = new_cloud_map[i][j];
		}
	}

}

void copy_water() {

	int search_dx[4] = { -1, -1, 1, 1 };
	int search_dy[4] = { -1, 1, -1, 1 };


	for (int i = 0; i < increased_basket.size(); i++) {	
		int _r = increased_basket[i].first;
		int _c = increased_basket[i].second;
		
		int cnt = 0;

		for (int j = 0; j < 4; j++) {
			int this_r = _r + search_dy[j];
			int this_c = _c + search_dx[j];
			
			if (this_r > -1 && this_r < N && this_c > -1 && this_c < N) {
				if (map[this_r][this_c] > 0) {
					cnt++;
				}
			}	
		}
		map[_r][_c] += cnt;
	}

}

void new_cloud() {

	//map 정보를 바탕으로 구름 생성 근데 cloud가 이미 있는 곳은 생기지 않게 할 것

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 1) {
				//구름 생성
				cloud[i][j] = !cloud[i][j]; //구름이 생겨야할 위치인데, 이미 구름이 있으면 구름을 없앰 / 구름이 없으면 구름을 만듦
				//물의 양 2 감소
				if (cloud[i][j] == true) {
					map[i][j] -= 2;
				}
			}
			else {
				if (cloud[i][j] == true) {
					cloud[i][j] = !cloud[i][j];
				}
			}
		}
	}

}
