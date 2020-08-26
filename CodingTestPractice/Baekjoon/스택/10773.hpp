#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int K,Num;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> Num;
		if (Num == 0)st.pop();
		else st.push(Num);
	}
	Num = 0;
	while (!st.empty()) {
		Num += st.top();
		st.pop();
	}
	cout << Num;
	return 0;
}