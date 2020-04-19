#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	if (n % 400 == 0)cout << "yes";
	else if (n % 100 != 0 && n % 4 == 0)cout << "yes";
	else cout << "no";
	return 0;
}