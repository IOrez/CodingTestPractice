#include <iostream>

using namespace std;
int a, b;

int table[10][4] = {
	{10,10,10,10},
	{1,1,1,1},
	{6,2,4,8},
	{1,3,9,7},
	{6,4,6,4},
	{5,5,5,5},
	{6,6,6,6},
	{1,7,9,3},
	{6,8,4,2},
	{1,9,1,9}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase; cin >> testCase;
	int a, b;
	while (testCase--) {
		cin >> a >> b;
		cout << table[a%10][b % 4]<<'\n';
	}
	return 0;
}