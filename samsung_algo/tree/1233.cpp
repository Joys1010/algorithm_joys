#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct my_node {
	string value;
	my_node* left_child;
	my_node* right_child;
};

my_node node[201];
int N;

string inorder_traversal(my_node* root) {
	string tmp1;
	string tmp2;
	if (root != nullptr) {
		tmp1 = inorder_traversal(root->left_child);
		string tmp = root->value;
		tmp2 = inorder_traversal(root->right_child);
	
	}
	return "";
}

int main(int argc, char** argv)
{
	int test_case;
	string str;
	string result;
	int flg = 1;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		flg = 1;

		for (int i = 0; i < 201; i++) {
			node[i].value = "";
			node[i].left_child = nullptr;
			node[i].right_child = nullptr;
		}

		cin >> N;
		cin.ignore();
		for (int i = 0; i < N; i++) {
			getline(cin, str);

			vector <string> tmp;
			char str_buf[50];
			strcpy(str_buf, str.c_str());
			char* ptr = strtok(str_buf, " ");

			while (ptr != nullptr) {
				tmp.push_back(string(ptr));
				ptr = strtok(nullptr, " ");
			}
			int num = stoi(tmp[0]);
			if (tmp.size() == 4) { //node_num 연산자(value) left_child right_child

				node[num].value = tmp[1];
				if (tmp[1] == "+" || tmp[1] == "-" || tmp[1] == "*" || tmp[1] == "/") {
				}
				else {
					if (num < (N / 2) + 1) {
						flg = false;
					}
				}
				node[num].left_child = &node[stoi(tmp[2])];
				node[num].right_child = &node[stoi(tmp[3])];
			}
			else { //node_num value
				if (tmp[1] == "+" || tmp[1] == "-" || tmp[1] == "*" || tmp[1] == "/") {
					if (num > (N / 2) + 1) {
						flg = false;
					}
				}
				node[num].value = tmp[1];
			}
		}
		
		cout << "#" << test_case << " " << flg << "\n";

	}
	return 0;
}
