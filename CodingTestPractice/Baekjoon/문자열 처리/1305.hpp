#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fail_func(vector<int>& vfail, int n, string str)
{
	vfail.resize(n);
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && str[i] != str[j])
			j = vfail[j - 1];

		if (str[i] == str[j])
			j++;

		vfail[i] = j;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int L;
	string str;
	cin >> L;
	cin >> str;

	vector<int> vfail;
	fail_func(vfail, L, str);

	int ans = L - vfail[L - 1];

	cout << ans;

}