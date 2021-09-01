#include<iostream>
#include<queue>
#include<string>
 
using namespace std;
 
int N;
 
int command;
int num;
string result;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        priority_queue <int> pq;
        result = "";
 
        cin >> N;
         
        for (int i = 0; i < N; i++) {
            cin >> command;
            if (command == 1) {
                cin >> num;
                pq.push(num);
            }
            else {
                if (pq.empty()) {
                    result += "-1 ";
                }
                else {
                    result +=  to_string(pq.top()) + " ";
                    pq.pop();
                }
            }
 
        }
        cout << "#" << test_case << " " << result << "\n";
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
