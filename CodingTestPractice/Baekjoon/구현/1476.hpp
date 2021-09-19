#include <iostream>

using namespace std;

int E, S, M,te,ts,tm,cnt;
int main() {
	cin >> E >> S >> M;
	while (true) {
		cnt++;
		te = (te + 1) % 16 ? (te + 1) % 16 : 1; 
		ts = (ts + 1) % 29 ? (ts + 1) % 29 : 1;
		tm = (tm + 1) % 20 ? (tm + 1) % 20 : 1;
		if (E == te && S == ts && M == tm)break;
 	}
	cout << cnt;
	return 0;
}