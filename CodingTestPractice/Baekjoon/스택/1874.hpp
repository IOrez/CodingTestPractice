#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, number;
vector<char> v;
stack<int> st;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int cnt = 0;
	bool check = true;
	for (int i = 1; i <= n&&check; ++i) {
		cin >> number;
		while (cnt+1 <= number) {
			v.push_back('+');
			st.push(++cnt);
		}
		check = false;
		while (!st.empty()&&st.top() >= number) {
			if (st.top() == number)check = true;
			v.push_back('-');
			st.pop();
		}
	}

	if (!check)
		cout << "NO" << '\n';
	else {
		for (auto& c : v) {
			cout << c << '\n';
		}
	}
	return 0;
}