#include <iostream>
#include <cmath>
using namespace std;

int N, R, C, Cnt = -1;
void solution(int n, int sr, int sc)
{
	if (n == 2)
	{
		int s = sr, c = sc; Cnt++;
		if (s == R && c == C) {
			cout << Cnt; exit(0);
		}
		s = sr; c = sc + 1; Cnt++;
		if (s == R && c == C) {
			cout << Cnt; exit(0);
		}
		s = sr + 1, c = sc; Cnt++;
		if (s == R && c == C) {
			cout << Cnt; exit(0);
		}
		s = sr + 1, c = sc + 1; Cnt++;
		if (s == R && c == C) {
			cout << Cnt; exit(0);
		}
	}
	else
	{
		int RPivot = sr + n / 2;
		int CPivot = sc + n / 2;
		if (R < RPivot && C < CPivot)
			solution(n / 2, sr, sc); 
		Cnt += (n / 2) * (n / 2);
		if (R < RPivot && C >= CPivot)
			solution(n / 2, sr, sc + n / 2);
		Cnt += (n / 2) * (n / 2);
		if (R >= RPivot && C < CPivot)
			 solution(n / 2, sr + n / 2 , sc); 
		Cnt += (n / 2) * (n / 2);
		if (R >= RPivot && C >= CPivot) {
			solution(n / 2, sr + n / 2 , sc + n / 2); 
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> R >> C;
	int length = pow(2, N);
	solution(length, 0, 0);
	return 0;
}