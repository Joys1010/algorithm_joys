#include<iostream>
#include<string>
 
using namespace std;
 
string books;
string word;
int answer;
int moveDist[100001];
 
void makeMoveTable() {
 
    int word_len = word.length();
    int j = 0;
 
    moveDist[0] = 0;
    for (int i = 1; i < word_len; i++) {
         
        while (j > 0 && word[j] != word[i]) {
            j = moveDist[j-1];
        }
 
        if (word[j] == word[i]) {
            moveDist[i] = ++j;
        }
    }
}
 
int doKMP() {
    int answer = 0;
 
    int books_len = books.length();
    int word_len = word.length();
 
    int j = 0;
 
    for (int i = 0; i < books_len; i++) {
        while (j > 0 && books[i] != word[j]) {
            j = moveDist[j - 1];
        }
        if (books[i] == word[j]) {
            if (j == word_len - 1) {
                answer++;
                j = moveDist[j];
            }
            else {
                j++;
            }
        }
    }
 
    return answer;
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    //freopen("input.txt", "r", stdin);
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        books = "";
        word = "";
        answer = 0;
 
        for (int i = 0; i < 100001; i++) {
            moveDist[i] = 0;
        }
 
        cin >> books;
        cin >> word;
 
 
        makeMoveTable();
        answer = doKMP();
         
        cout << "#" << test_case << " " << answer << "\n";
 
    }
    return 0;
}
