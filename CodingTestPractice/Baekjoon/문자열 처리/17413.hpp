#include <iostream>
#include <stack>
#include <string>
using namespace std;

string input;
stack<char> st;

void printStack() {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

void sol()
{
	bool isTag = false;
	int len = input.size();
	for(auto ch:input){
		if (isTag) {
			if (ch == '>')isTag = false;
			cout << ch;
		}
		else {
			if (ch == ' ' || ch == '<') {
				if (ch == '<')isTag = true;
				printStack();
				cout << ch;
			}
			else st.push(ch);
		}
	}
	printStack();
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	getline(cin, input);
	sol();
	return 0;
}