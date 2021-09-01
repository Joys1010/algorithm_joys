#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

void addNode2Head(int data)
{
	Node* new_node = getNode(data);

	Node* tmp = head->next;

	if (tmp == nullptr) {
		head->next = new_node;
		new_node->prev = head;
	}
	else {
		tmp->prev = new_node;
		new_node->next = tmp;
		new_node->prev = head;
		head->next = new_node;
	}
}

void addNode2Tail(int data)
{
	Node* tmp = head;
	Node* new_node = getNode(data);

	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}

	tmp->next = new_node;
	new_node->prev = tmp;
}

void addNode2Num(int data, int num)
{
	Node* tmp = head;
	Node* now;
	Node* new_node = getNode(data);
	int cnt = 0;

	for (int i = 0; i < num - 1; i++) {
		cnt++;
		tmp = tmp->next;
		if (tmp == nullptr) {
			return;
		}
	}

	Node* tmp2 = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = tmp2;
	if (tmp2 != nullptr) {
		tmp2->prev = new_node;
	}
}

int findNode(int data)
{
	int cnt = 1;
	Node* tmp = head->next;
	while (tmp->data != data) {
		tmp = tmp->next;
		cnt++;
	}
	return cnt;
}

void removeNode(int data)
{
	Node* tmp = head;
	while (tmp->next->data != data) {
		tmp = tmp->next;
		if (tmp->next == nullptr) {
			return;
		}
	}
	tmp->next = tmp->next->next;
	if (tmp->next != nullptr) {
		tmp->next->prev = tmp;
	}

}

int getList(int output[MAX_NODE])
{
	int cnt = 0;
	Node* tmp = head->next;
	while (tmp->next != nullptr) {
		output[cnt++] = tmp->data;
		tmp = tmp->next;
	}
	output[cnt++] = tmp->data;
	return cnt;
}

int getReversedList(int output[MAX_NODE])
{
	Node* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	int cnt = 0;
	while (tmp->prev != nullptr) {
		output[cnt++] = tmp->data;
		tmp = tmp->prev;
	}
	return cnt;
}


