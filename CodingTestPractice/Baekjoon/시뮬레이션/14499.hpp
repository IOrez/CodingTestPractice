#include <iostream>

using namespace std;

int N, M, X, Y, K;
int dice[6] = { 0,0,0,0,0,0 };
int table[20][20];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

enum Direction {
	EAST,
	WAST,
	NORTH,
	SOUTH
};

void Action(Direction dir) {
	int tmp;
	switch (dir) {
	case Direction::EAST:
		tmp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[4];
		dice[4] = tmp;
		break;
	case Direction::WAST:
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[5];
		dice[5] = tmp;
		break;
	case Direction::NORTH:
		tmp = dice[0];
		for (int i = 0; i < 3; ++i)
			dice[i] = dice[i + 1];
		dice[3] = tmp;
		break;
	case Direction::SOUTH:
		tmp = dice[3];
		for (int i = 3; i > 0; --i)
			dice[i] = dice[i - 1];
		dice[0] = tmp;
		break;
	}
}

void ChangeNum() {
	if (table[Y][X] == 0) {
		table[Y][X] = dice[2];
	}
	else {
		dice[2] = table[Y][X];
		table[Y][X] = 0;
	}
}

bool IsInRange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> Y >> X >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> table[i][j];

	int order;
	while (K--) {
		cin >> order;
		order -= 1;
		if (!IsInRange(Y + dy[order], X + dx[order]))continue;
		Direction dir = (Direction)order;
		Action(dir);
		Y += dy[order]; X += dx[order];
		ChangeNum();
		cout << dice[0]<<'\n';
	}

	return 0;
}