#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
 
int N, mid;
int X, Y;
unsigned long long answer;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        answer = 0;
 
        cin >> N >> mid;
 
        priority_queue<int, vector<int>, greater<int>> big_nums;
        priority_queue<int, vector<int>, less<int>> small_nums;
 
        for (int i = 0; i < N; i++) {
            cin >> X >> Y;
             
            if (X > mid) {
                big_nums.push(X);
            }
            else {
                small_nums.push(X);
            }
 
            if (Y > mid) {
                big_nums.push(Y);
            }
            else {
                small_nums.push(Y);
            }
            //크기가 같으면?
 
 
            while (small_nums.size() > big_nums.size()) { //작은 수가 더 많으면
                big_nums.push(mid);
                mid = small_nums.top();
                small_nums.pop();
            }
 
            while (big_nums.size() > small_nums.size()) { //큰 수가 더 많으면
                small_nums.push(mid);
                mid = big_nums.top();
                big_nums.pop();
            }
            answer += mid; 
            answer %= 20171109;
 
        }
 
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
