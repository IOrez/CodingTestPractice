#include <iostream>
#include <vector>
using namespace std;

#define SIZE	9 

vector<int> con;

int N, M;
bool check[SIZE];

void solution() {
	if (con.size() == M) {
		for (auto& i : con) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (check[i])continue;
		check[i] = true; con.push_back(i);
		solution();
		check[i] = false; con.pop_back();
	}

}

int main() {
	cin >> N >> M;
	solution();
}