#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	int cnt = 0;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	cin >> input;
	regex re(R"(c=|c-|dz=|d-|lj|nj|s=|z=|[a-z-=])");
	smatch mat;
	while (regex_search(input, mat, re)) {
		cnt += 1;
		input = mat.suffix();
	}
	cout << cnt;

	return 0;
}