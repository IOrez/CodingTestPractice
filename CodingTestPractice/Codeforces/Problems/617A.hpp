#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int result = n / 5;
	if (n % 5)result += 1;
	cout << result;

	return 0;
}