#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int _data;
	vector<struct node*> _vpChild;
	struct node* _pParent = nullptr;
}Node;


Node node[50];
int Cnt;

void Solution(int Root)
{
	if (node[Root]._vpChild.empty())
	{
		Cnt++;
		return;
	}
	for (auto n : node[Root]._vpChild)
		Solution(n->_data);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,_parent, Root, Remove;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		node[i]._data = i;
		cin >> _parent;
		if (_parent == -1)Root = i;
		else
		{
			node[_parent]._vpChild.push_back(&node[i]);
			node[i]._pParent = &node[_parent];
		}
	}
	cin >> Remove;
	if (Remove != Root)
	{
		auto& v = node[Remove]._pParent->_vpChild;
		v.erase(find(v.begin(), v.end(), &node[Remove]));
		Solution(Root);
	}
	cout << Cnt;

	return 0;
}