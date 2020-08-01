#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	bool check = false;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		bool isHard; cin >> isHard;
		if (isHard)check = true;
	}
	if (check)cout << "HARD";
	else cout << "EASY";
	return 0;
}