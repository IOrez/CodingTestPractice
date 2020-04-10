#include <iostream>

using namespace std;

int Stack[1001];
int top = -1;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	while (N--)
		cin >> Stack[++top];

	while (top >= 0)
		cout << Stack[top--]<<" ";


	return 0;
}