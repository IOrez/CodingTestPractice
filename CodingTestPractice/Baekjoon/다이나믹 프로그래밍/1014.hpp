#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int T, N, M;
string input;

/*
	 최선의 방법을 특정 열에 배치할 수 있는 학생을 모두 배치하고 그 다음 열에 대해서
	배치한 학생들의 자리에 대하여 배치할 수 없는 곳을 업데이트 하고 다음 열에 대해서 
	이 같은 방법을 반복하는 것이라 생각하였음.

	 DP의 인덱스는 반영한 열을 bit로 표시하여 맵핑한 것,
	예로 5열에서 1열,3열,4열을 선택하였다면 01101 (아래의 코드의 방법으로 수를 표현)..

	 DP의 갱신 방법은 최근 업데이트된 테이블의 해당열에서 배치할 수 있는 학생수를 구하고
	이전 반영한 열들에서 배치할 수 있는 총 학생 수를 더하여 해당 열을 포함하여 구한 인덱스를
	DP에 적용.

*/


int table[10][10];	// 입력값으로 담길 변수들 (학생이 앉을 수 있는 곳: 1, 학생이 앉을 수 없는 곳: 0)
int DP[1 << 10];	// 모든 순서를 다 고려했을 때 나올 수 있는 최대 값을 1<<10으로 표현	
int ans = 0;		// 최종 답이 담길 변수

void Recursive(int i,int bit) {	// 이전 순서를 기반으로 정한 열을 순서에 반영하여 DP를 갱신하는 재귀함수
	if (i == M) {
		ans = max(ans, DP[bit]); // 모든 열에 대하여 순서가 정해 졌다면 최종 답을 갱신
		return;
	}
	
	int newbit = bit | 1 << i; // 지금의 열을 포함한 새로운 순서를 표현한 bit인덱스

	if (i == M-1) {	// 마지막 열을 검사하였을 경우 이전의 계산을 하지 않고 바로 최종 답을 구하도록 한다.
		int result = 0;
		for (int j = 0; j < N; ++j)result += table[j][i];
		DP[newbit] = DP[bit] + result;
		Recursive(i + 1, newbit);
		return;
	}

	int ctable[10];
	for (int j = 0; j < N; ++j)ctable[j] = table[j][i + 1]; // 기존 테이블의 행 정보를 저장
	for (int j = 0; j < N; ++j) {
		if (table[j][i] == 0)continue;
		table[j][i + 1] = 0;
		if (N != 1) {
			if (j == 0)table[j + 1][i + 1] = 0; // 첫번째 행일 경우 행의 크기가 1이 아니라면 다음 열의 두번째 행을 학생이 앉지 못하도록 한다.
			else if (j == N - 1)table[j - 1][i + 1] = 0; // 마지막 행일 경우 다음 열의 이전 행을 학생이 앉지 못하도록 한다.
			else table[j - 1][i + 1] = table[j + 1][i + 1] = 0; // 그 외의 경우에는 다음 열의 이전, 이후 행을 학생이 앉지 못하도록 한다.
		}
	}

	int result = 0;
	for (int j = 0; j < N; ++j)result += table[j][i]; // 지금 행에서 학생이 앉을 수 있는 최댓값을 구한다.
	DP[newbit] = DP[bit] + result; // 이전 순서에 지금 구한 열에서 최댓값을 더한다.
	for (int j = i + 1; j <= M; ++j)
		Recursive(j, newbit); // 지금 열을 기준으로 다음 행부터 이를 반복한다.
	
	
	for (int j = 0; j < N; ++j)table[j][i + 1] = ctable[j]; // 테이블 행 정보 복구
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while (T--) {
		memset(DP, 0, sizeof(DP));
		ans = 0;
		cin >> N >> M; cin.ignore();
		for (int i = 0; i < N; ++i) {
			getline(cin, input);
			for (int j = 0; j < M; ++j) {
				if (input[j] == '.')table[i][j] = 1;
				else if (input[j] == 'x')table[i][j] = 0;
			}
		}
		for (int i = 0; i < M; ++i) // 첫번째 순서의 기준을 모두 검사한다.
			Recursive(i, 0);
		cout << ans << '\n';
	}
	
	return 0;
}