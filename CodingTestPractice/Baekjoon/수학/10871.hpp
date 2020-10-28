#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N,X,Num;
	cin >> N >> X;
	while (N--) {
		cin >> Num;
		if (Num < X)cout << Num << " ";
	}
	return 0;
}