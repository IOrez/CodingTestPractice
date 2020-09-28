#include <iostream>
#include <string>
using namespace std;

typedef struct nodeList NodeList;

typedef struct node {
	bool have = false;
	NodeList* link = nullptr;
}Node;

typedef struct nodeList {
	Node nodes[10];
}NodeList;

bool insert(NodeList*& pNodeList, string a_str, int idx) {
	if (a_str.size() >= idx + 1) {
		if (pNodeList == nullptr) {
			pNodeList = new NodeList;
		}
		if (pNodeList->nodes[a_str[idx] - '0'].have)return false;
		if (a_str.size() == idx + 1) {
			if (pNodeList->nodes[a_str[idx] - '0'].link != nullptr)return false;
			pNodeList->nodes[a_str[idx] - '0'].have = true;
			return true;
		}
		return insert(pNodeList->nodes[a_str[idx] - '0'].link, a_str, idx + 1);
	}
}

void del(NodeList*& pNodeList) {
	if (pNodeList == nullptr)return;
	for (int i = 0; i < 10; ++i)
		if (pNodeList->nodes[i].link != nullptr)del(pNodeList->nodes[i].link);
	delete pNodeList;
	return;
}

void init(NodeList*& pNodeList) {
	if (pNodeList == nullptr)return;
	for (int i = 0; i < 10; ++i) {
		pNodeList->nodes[i].have = false;
		if (pNodeList->nodes[i].link != nullptr)init(pNodeList->nodes[i].link);
	}
	return;
}

int testCase, Number;
string input;
NodeList* pNodeList;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> testCase;
	while (testCase--) {
		pNodeList = new NodeList;
		init(pNodeList);
		cin >> Number;
		bool result = true;
		for (int i = 0; i < Number; ++i) {
			cin >> input;
			if (result)
				result = insert(pNodeList, input, 0);
		}
		if (result)cout << "YES" << '\n';
		else cout << "NO" << '\n';
		del(pNodeList);
	}
	return 0;
}