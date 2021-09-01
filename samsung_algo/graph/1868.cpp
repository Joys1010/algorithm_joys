#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;
 
int N;
int map[300][300];
int visited[300][300];
string line;
int click;
queue <pair<int, int>> q;
 
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
     
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        click = 0;
 
        cin >> N;
 
        for (int i = 0; i < N; i++) {
            cin >> line;
            for (int j = 0; j < N; j++) {
                if (line[j] == '.') {
                    map[i][j] = -2;
                }
                else if (line[j] == '*') {
                    map[i][j] = -1;
                    visited[i][j] = 1;
                }
            }
        }
 
        for (int i = 0; i < N; i++) { //y인덱스
            for (int j = 0; j < N; j++) { //x인덱스
                int mine = 0;
                //주변 8칸 구경
                if (map[i][j] == -1) {
                    continue;
                }
 
                for (int k = -1; k <= 1; k++) { //y인덱스
                    for (int l = -1; l <= 1; l++) { //x인덱스
                        if (i + k < 0 || i + k > N - 1 || j + l < 0 || j + l > N - 1) { //map을 벗어나면
                            continue;
                        }
                        else {
                            if (map[i + k][j + l] == -1) {
                                mine++;
                            }
                        }
                    }
                }
                map[i][j] = mine;
            }
        }
         
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                 
                if (map[i][j] == 0 && visited[i][j] != 1) {
                    //bfs 시작
                    q.push({ i,j });
 
                    while (!q.empty()) {
                        int now_y = q.front().first;
                        int now_x = q.front().second;
 
                        q.pop();
                         
                        if (visited[now_y][now_x] != 1) {
                            click++;
                            visited[now_y][now_x] = 1;
                        }
 
                        for (int k = -1; k <= 1; k++) { //y인덱스
                            for (int l = -1; l <= 1; l++) { //x인덱스
                                if (now_y + k < 0 || now_y + k > N - 1 || now_x + l < 0 || now_x + l > N - 1) { //map을 벗어나면
                                    continue;
                                }
                                else {
 
                                    if (map[now_y + k][now_x + l] == 0 && visited[now_y + k][now_x + l] != 1) {
                                        q.push({ now_y + k, now_x + l });
                                    }
                                    visited[now_y + k][now_x + l] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] != 1) {
                    click++;
                }
            }
        }
 
        cout << "#" << test_case << " " << click << "\n";
    }
 
     
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
