#include <iostream>
#include <vector>
#include <functional>
using namespace std;


#define MAX_SIZE 17

enum class type {
	hori,vert,dia
};

int N;
int area[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][3];
int dy[3] = { 0,1,1 };
int dx[3] = { 1,0,1 };

bool isInRange(int y, int x) {
	return 1 <= y && y <= N && 1 <= x && x <= N;
}

bool isCorrect(int y, int x) {
	bool result = isInRange(y, x);
	if (result) result = !area[y][x];
	return result;
}

function<bool(int, int)> func[3][3] = {
	{[](int r,int c)->bool {return isCorrect(r,c + 1); },NULL,[](int r,int c)->bool {return isCorrect(r,c + 1) && isCorrect(r + 1,c + 1) && isCorrect(r + 1,c); }},
	{NULL,[](int r,int c)->bool {return isCorrect(r + 1,c); },[](int r,int c)->bool {return isCorrect(r,c + 1) && isCorrect(r + 1,c + 1) && isCorrect(r + 1,c); }},
	{[](int r,int c)->bool {return isCorrect(r,c + 1); },[](int r,int c)->bool {return isCorrect(r + 1,c); },[](int r,int c)->bool {return isCorrect(r,c + 1) && isCorrect(r + 1,c + 1) && isCorrect(r + 1,c); }}
};

int solution(int r,int c, type e_type) {
	if (r == N && c == N)return 1;
	if (dp[r][c][(int)e_type] != 0)return dp[r][c][(int)e_type];

	int result = 0;
	for (int i = 0; i < 3; ++i) {
		if (func[(int)e_type][i] == NULL)continue;
		if (func[(int)e_type][i](r,c)) result += solution(r + dy[i], c + dx[i], (type)i);
	}
	dp[r][c][(int)e_type] = result;
	return dp[r][c][(int)e_type];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= N; ++x)
			cin >> area[y][x];

	cout << solution(1, 2, type::hori);
	
	return 0;
}