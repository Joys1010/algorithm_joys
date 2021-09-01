#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

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

void addNode2Head(int data)
{
	Node* new_node = getNode(data);
	new_node->next = head->next;
	head->next = new_node;
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

void addNode2Num(int data, int num)
{
	Node* tmp = head;
	Node* new_node = getNode(data);

	for (int i = 0; i < num - 1; i++) {
		tmp = tmp->next;
	}

	Node* tmp2 = tmp->next;
	tmp->next = new_node;
	new_node->next = tmp2;
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
