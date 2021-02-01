#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define SIZE	101

enum class Type {
	EMPTY, BODY, APPLE
};

enum class Direction {
	LEFT,UP,RIGHT,DOWN,NONE
};


int N,K,L;
Type Table[SIZE][SIZE];
queue<pair<int, int>> Pattern;
queue<pair<int, int>> snake;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

bool isInRange(int y, int x) {
	return 1 <= y && y <= N && 1 <= x && x <= N;
}


int solution() {
	int tick = 0;
	int turnTime = 0;
	int turnDir = 0;
	
	int HeadX=1, HeadY=1;
	Direction HeadDir = Direction::RIGHT;

	Table[HeadY][HeadX] = Type::BODY;
	snake.push({ HeadY,HeadX });

	if (!Pattern.empty()) {
		turnTime = Pattern.front().first;
		turnDir = Pattern.front().second;
		Pattern.pop();
	}

	while (true) {
		tick++;
		HeadY += dy[(int)HeadDir]; HeadX += dx[(int)HeadDir];
		if (!isInRange(HeadY, HeadX))break;
		else if (Table[HeadY][HeadX] == Type::BODY)break;

		if (Table[HeadY][HeadX] != Type::APPLE) {
			auto [TailY, TailX] = snake.front(); snake.pop();
			Table[TailY][TailX] = Type::EMPTY;
		}

		Table[HeadY][HeadX] = Type::BODY;
		snake.push({ HeadY,HeadX });

		if (turnTime == tick) {
			int idx = ((int)HeadDir + turnDir) % 4;
			if (idx < 0)idx += 4;
			HeadDir = (Direction)(idx);
		}

		if (!Pattern.empty() && turnTime == tick) {
			turnTime = Pattern.front().first;
			turnDir = Pattern.front().second;
			Pattern.pop();
		}		
	}

	return tick;
}

int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int y, x;
		cin >> y >> x;
		Table[y][x] = Type::APPLE;
	}

	cin >> L; cin.ignore();
	for (int i = 0; i < L; ++i) {
		string str;
		getline(cin, str);
		int idx = str.find_first_of(' ');
		int t = stoi(str.substr(0, idx));
		int dir = str[idx + 1] == 'D' ? 1 : -1;
		Pattern.push({t,dir });
	}

	int result = solution();
	cout << result;
	return 0;
}