#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	string order;
	getline(cin,input);
	list<char> output(input.begin(),input.end());
	list<char>::iterator iter = output.end();
	int N;
	cin >> N; cin.ignore();
	while (N--) {
		getline(cin, order);
		switch (order[0]) {
		case 'L':
			if (iter != output.begin())iter--;
			break;
		case 'D':
			if (iter != output.end())iter++;
			break;
		case 'B':
			if (iter != output.begin()) {
				iter = output.erase(--iter);
			}
			break;
		case 'P':
			if (iter == output.end()) {
				output.push_back(order[2]);
				iter = output.end();
			}
			else output.insert(iter, order[2]);
			break;
		}
	}
	iter = output.begin();
	while (iter != output.end())
		cout << *iter++;
	return 0;
}

