#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int T, N, M;
string input;

/*
	 �ּ��� ����� Ư�� ���� ��ġ�� �� �ִ� �л��� ��� ��ġ�ϰ� �� ���� ���� ���ؼ�
	��ġ�� �л����� �ڸ��� ���Ͽ� ��ġ�� �� ���� ���� ������Ʈ �ϰ� ���� ���� ���ؼ� 
	�� ���� ����� �ݺ��ϴ� ���̶� �����Ͽ���.

	 DP�� �ε����� �ݿ��� ���� bit�� ǥ���Ͽ� ������ ��,
	���� 5������ 1��,3��,4���� �����Ͽ��ٸ� 01101 (�Ʒ��� �ڵ��� ������� ���� ǥ��)..

	 DP�� ���� ����� �ֱ� ������Ʈ�� ���̺��� �ش翭���� ��ġ�� �� �ִ� �л����� ���ϰ�
	���� �ݿ��� ���鿡�� ��ġ�� �� �ִ� �� �л� ���� ���Ͽ� �ش� ���� �����Ͽ� ���� �ε�����
	DP�� ����.

*/


int table[10][10];	// �Է°����� ��� ������ (�л��� ���� �� �ִ� ��: 1, �л��� ���� �� ���� ��: 0)
int DP[1 << 10];	// ��� ������ �� ������� �� ���� �� �ִ� �ִ� ���� 1<<10���� ǥ��	
int ans = 0;		// ���� ���� ��� ����

void Recursive(int i,int bit) {	// ���� ������ ������� ���� ���� ������ �ݿ��Ͽ� DP�� �����ϴ� ����Լ�
	if (i == M) {
		ans = max(ans, DP[bit]); // ��� ���� ���Ͽ� ������ ���� ���ٸ� ���� ���� ����
		return;
	}
	
	int newbit = bit | 1 << i; // ������ ���� ������ ���ο� ������ ǥ���� bit�ε���

	if (i == M-1) {	// ������ ���� �˻��Ͽ��� ��� ������ ����� ���� �ʰ� �ٷ� ���� ���� ���ϵ��� �Ѵ�.
		int result = 0;
		for (int j = 0; j < N; ++j)result += table[j][i];
		DP[newbit] = DP[bit] + result;
		Recursive(i + 1, newbit);
		return;
	}

	int ctable[10];
	for (int j = 0; j < N; ++j)ctable[j] = table[j][i + 1]; // ���� ���̺��� �� ������ ����
	for (int j = 0; j < N; ++j) {
		if (table[j][i] == 0)continue;
		table[j][i + 1] = 0;
		if (N != 1) {
			if (j == 0)table[j + 1][i + 1] = 0; // ù��° ���� ��� ���� ũ�Ⱑ 1�� �ƴ϶�� ���� ���� �ι�° ���� �л��� ���� ���ϵ��� �Ѵ�.
			else if (j == N - 1)table[j - 1][i + 1] = 0; // ������ ���� ��� ���� ���� ���� ���� �л��� ���� ���ϵ��� �Ѵ�.
			else table[j - 1][i + 1] = table[j + 1][i + 1] = 0; // �� ���� ��쿡�� ���� ���� ����, ���� ���� �л��� ���� ���ϵ��� �Ѵ�.
		}
	}

	int result = 0;
	for (int j = 0; j < N; ++j)result += table[j][i]; // ���� �࿡�� �л��� ���� �� �ִ� �ִ��� ���Ѵ�.
	DP[newbit] = DP[bit] + result; // ���� ������ ���� ���� ������ �ִ��� ���Ѵ�.
	for (int j = i + 1; j <= M; ++j)
		Recursive(j, newbit); // ���� ���� �������� ���� ����� �̸� �ݺ��Ѵ�.
	
	
	for (int j = 0; j < N; ++j)table[j][i + 1] = ctable[j]; // ���̺� �� ���� ����
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
		for (int i = 0; i < M; ++i) // ù��° ������ ������ ��� �˻��Ѵ�.
			Recursive(i, 0);
		cout << ans << '\n';
	}
	
	return 0;
}