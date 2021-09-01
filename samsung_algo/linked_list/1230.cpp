/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#define MAX_NODE 10000

using namespace std;

struct Node {
	int data;
	Node* next;
};


Node* head;
Node node[MAX_NODE];
int nodeCnt;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
	head->next = nullptr;
}

void addNode2Tail(int data)
{
	Node* tmp = head;
	Node* new_node = getNode(data);

	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}

	tmp->next = new_node;
}
void tmp_list_addNode2Tail(Node *tmp_head, int data)
{
	Node* tmp = tmp_head;
	Node* new_node = getNode(data);

	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}

	tmp->next = new_node;
}
void addList2Tail(Node *tmp_head)
{
	Node* tmp = head;

	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}

	tmp->next = tmp_head;
}

void addList2Num(Node* tmp_head, int num)
{
	Node* tmp = head;

	for (int i = 0; i < num - 1; i++) {
		tmp = tmp->next;
	}

	Node* tmp2 = tmp->next;
	
	Node* tmp_tail = tmp_head;
	while (tmp_tail->next != nullptr) {
		tmp_tail = tmp_tail->next;
	}

	tmp_tail->next = tmp2;
	tmp->next = tmp_head;
	
}

void deleteList2Num(int location, int cnt)
{

	Node* tmp = head;

	for (int i = 0; i < location - 1; i++) {
		tmp = tmp->next;
	}

	Node* tmp2 = tmp->next;

	Node* del_list = tmp->next;
	for (int i = 0; i < cnt - 1; i++) {
		del_list = del_list->next;
	}

	tmp->next = del_list->next;

}

/*void getList()
{

	int cnt = 0;
	Node* tmp = head->next;
	while (tmp->next != nullptr) {
		//output[cnt++] = tmp->data;
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << tmp->data << "\n";

	//output[cnt++] = tmp->data;
	//return cnt;
}*/

int main(int argc, char** argv)
{
	int test_case;


	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int secret_length;
		int secret_data;
		
		cin >> secret_length;
		init();

		//원본 암호문 링크드 리스트 만들기
		for (int i = 1; i <= secret_length; i++) {
			cin >> secret_data;
			addNode2Tail(secret_data);
		}

		int command_num;
		char command;
		int command_location;
		int command_first;
		int command_second;
		Node* tmp_head = nullptr;

		cin >> command_num;

		for (int i = 1; i <= command_num; i++) {
			cin >> command;

			switch (command) {

			case 'I' :
				cin >> command_location;
				cin >> command_first;
				
				//s의 list 만들기

				for (int j = 1; j <= command_first; j++) {
					int data;
					cin >> data;
					if (j == 1) {
						tmp_head = getNode(data);
					}
					else {
						tmp_list_addNode2Tail(tmp_head, data);
					}
				}
				//x 뒤에 붙이기
				addList2Num(tmp_head, command_location + 1);

				break;
			case 'D' :

				cin >> command_location;
				cin >> command_first;
				deleteList2Num(command_location + 1, command_first);

				break;

			case 'A' :
				cin >> command_first;

				for (int j = 1; j <= command_first; j++) {
					int data;
					cin >> data;
					if (j == 1) {
						tmp_head = getNode(data);
					}
					else {
						tmp_list_addNode2Tail(tmp_head, data);
					}
				}
				addList2Tail(tmp_head);
				
				break;
			}
		}

		//결과 출력
		cout << "#" << test_case << " ";
		Node* result = head->next;
		for (int i = 1; i <= 10; i++) {
			cout << result->data << " ";
			result = result->next;
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
