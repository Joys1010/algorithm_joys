#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N;

struct my_node {
	string value;
	my_node* left_child;
	my_node* right_child;
};

my_node node[1001];

float inorder_traversal(my_node* root) {
	float tmp1;
	float tmp2;
	if (root != nullptr) {
		tmp1 = inorder_traversal(root->left_child);
		string tmp = root->value;
		tmp2 = inorder_traversal(root->right_child);
		if (tmp == "+") {
			return tmp1 + tmp2;
		}
		else if (tmp == "-") {
			return tmp1 - tmp2;
		}
		else if (tmp == "*") {
			return tmp1 * tmp2;
		}
		else if (tmp == "/") {
			return tmp1 / tmp2;
		}
		else {
			return stoi(tmp);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string str;
	int result;

	for (test_case = 1; test_case <= 10; ++test_case)
	{

		for (int i = 0; i < 1001; i++) {
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
				node[num].left_child = &node[stoi(tmp[2])];
				node[num].right_child = &node[stoi(tmp[3])];
			}
			else { //node_num value
				node[num].value = tmp[1];
			}
		}
		result = inorder_traversal(&node[1]);

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}
