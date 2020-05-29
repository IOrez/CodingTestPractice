#include <iostream>
#include <string>
using namespace std;

constexpr int Size = 'Z' - 'A' + 1;

typedef struct node
{
	char data;
	struct node* left = nullptr;
	struct node* right = nullptr;
}Node;

Node n[Size];

void preorder(Node* root)
{
	if (root == nullptr)return;
	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root)
{
	if (root == nullptr)return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}

void postorder(Node* root)
{
	if (root == nullptr)return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	string input;
	cin >> N; cin.ignore();
	for (int i = 0; i < Size; ++i)n[i].data = i + 'A';
	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);
		if (input[2] != '.')n[input[0] - 'A'].left = &n[input[2] - 'A'];
		if (input[4] != '.')n[input[0] - 'A'].right = &n[input[4] - 'A'];
	}
	preorder(n); cout << '\n';
	inorder(n); cout << '\n';
	postorder(n);
	return 0;
}