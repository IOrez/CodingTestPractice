#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int Q, Mod;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> Q >> Mod;
	vector<int> check(Mod, 0);
	vector<list<int>> table(Mod);
	int num = 0, order = 0;

	for (int i = 0; i < Q; ++i) {
		cin >> num;
		switch (num) {
		case 1:
			cin >> num; order++;
			table[num % Mod].insert(table[num % Mod].begin(), order);
			break;
		case 2:
			for (int i = 0; i < Mod; ++i) {
				if (table[i].empty())continue;
				if (*table[i].begin() == order) {
					table[i].erase(table[i].begin());
					order--;
					break;
				}
			}
			break;
		case 3:
			bool check = true;
			int later = order;
			for (int i = 0; i < Mod && check; ++i) {
				if (table[i].empty())check = false;
				else
					later = min(later, *table[i].begin());
			}
			if (!check)
				cout << -1 << '\n';
			else
				cout << order - later + 1 << '\n';
			break;
		}
	}
	return 0;
}