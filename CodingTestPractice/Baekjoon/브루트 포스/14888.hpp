#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

int A[100],Num;
vector<int> S(4);

int Min = numeric_limits<int>::max();
int Max = numeric_limits<int>::min();

void solution(int result,int idx) {
	if (idx == Num) {
		Min = min(result, Min);
		Max = max(result, Max);
		return;
	}
	if (idx == 0) {
		result += A[idx];
		solution(result, idx + 1);
	}
	else
	{
		for (int i = 0; i < 4;++i) {
			if (S[i] == 0)continue;
			switch (i) {
			case 0:
				result += A[idx]; S[i]--;
				solution(result, idx+1);
				result -= A[idx]; S[i]++;
				break;
			case 1:
				result -= A[idx]; S[i]--;
				solution(result, idx+1);
				result += A[idx]; S[i]++;
				break;
			case 2:
				result *= A[idx]; S[i]--;
				solution(result, idx+1);
				result /= A[idx]; S[i]++;
				break;
			case 3:
				result /= A[idx]; S[i]--;
				solution(result, idx+1);
				result *= A[idx]; S[i]++;
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> Num;
	for (int i = 0; i < Num; ++i)cin >> A[i];
	for (auto& i : S)cin >> i;
	solution(0,0);
	cout << Max << '\n' << Min << '\n';
	return 0;

}