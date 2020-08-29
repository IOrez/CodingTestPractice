#include <iostream>

typedef struct node {
	int data;
	struct node* LLink;
	struct node* RLink;
}Node;

using namespace std;
int N, K;

Node	nodes[5002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i <= N; ++i) {
		nodes[i].data = i;
		nodes[i].LLink = &nodes[i-1];
		nodes[i].RLink = &nodes[i+1];
	}
	nodes[1].LLink = &nodes[N];
	nodes[N].RLink = &nodes[1];
	cout << "<";
	int i = 0;
	while (true) {
		Node* pLink = &nodes[i];
		for (int i = 0; i < K; ++i)
			pLink = pLink->RLink;
		
		i = pLink->data;;
		cout << i;
		pLink->LLink->RLink = pLink->RLink;
		pLink->RLink->LLink = pLink->LLink;
		N--;
		if (N == 0)break;
		else cout << ", ";
	}
	cout << ">";
	return 0;
}