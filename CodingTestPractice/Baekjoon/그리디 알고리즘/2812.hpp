#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	string s;
	cin >> N >> K;
	cin >> s;
	int cnt = 0;
	deque<char> deq;
	deq.push_back(s[0]);
	int idx = 1;
	while (cnt != K&&idx<N)
	{
		if(deq.empty())deq.push_back(s[idx++]);

		char c_val = deq.back();
		if (c_val < s[idx]) { deq.pop_back(); cnt++; }
		else deq.push_back(s[idx++]);
	}
	while (cnt != K) { deq.pop_back(); cnt++; }
	while (idx < N)deq.push_back(s[idx++]);
	for (auto i : deq)
		cout << i;
	return 0;
}