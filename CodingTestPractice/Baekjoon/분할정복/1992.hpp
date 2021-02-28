#include <iostream>
#include <string>
using namespace std;

int N;

string table[64];

string quadtree(int left, int top, int right, int bottom) {
	string res = "";
	char ch = table[top][left];
	bool check = true;
	for (int i = top; i < bottom && check; ++i)
		for (int j = left; j < right && check; ++j)
			if (ch != table[i][j])check = false;

	if (!check){
		int rowMid = (top + bottom) / 2;
		int colMid = (left + right) / 2;
		res += "(" + quadtree(left, top, colMid, rowMid)
			+ quadtree(colMid, top, right, rowMid)
			+ quadtree(left, rowMid, colMid, bottom)
			+ quadtree(colMid, rowMid, right, bottom) + ")";
	}
	else
		res += ch;
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N; cin.ignore();
	for (int i = 0; i < N; ++i)
		getline(cin, table[i]);

	cout << quadtree(0, 0, N, N);

	return 0;
}