#include <iostream>

using namespace std;

void recursion(int n)
{
	if (n < 1)return;
	cout << n << endl;
	recursion(n - 1);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	recursion(n);

	return 0;
}