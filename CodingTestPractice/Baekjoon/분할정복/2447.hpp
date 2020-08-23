#include <iostream>
#include <cmath>
using namespace std;

void solution(char** table,int len,int posy,int posx) {
	if (len == 3) {
		for (int i = posy; i < posy + 3; ++i)
			for (int j = posx; j < posx + 3; ++j) {
				if (i == posy + 1 && j == posx + 1)continue;
				table[i][j] = '*';
			}
	}
	else
	{
		solution(table, len / 3, posy, posx);
		solution(table, len / 3, posy, posx + len / 3);
		solution(table, len / 3, posy, posx + 2 * len / 3);
		solution(table, len / 3, posy + len / 3, posx);
		solution(table, len / 3, posy + len / 3, posx + 2 * len / 3);
		solution(table, len / 3, posy + 2 * len / 3, posx);
		solution(table, len / 3, posy + 2 * len / 3, posx + len / 3);
		solution(table, len / 3, posy + 2 * len / 3, posx + 2 * len / 3);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	char** table = new char* [N];
	for (int i = 0; i < N; ++i)
		table[i] = new char[N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			table[i][j] = ' ';

	solution(table, N, 0, 0);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << table[i][j];
		cout << '\n';
	}
	for (int i = 0; i < N; ++i)
		delete[] table[i];
	delete[] table;
	return 0;
}