#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string dir[] = { "R","L","B","T","RT","LT","RB","LB" };
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,-1,1,1,1,-1,-1 };
char row[] = { '1','2','3','4','5','6','7','8' };
char col[] = { 'A','B','C','D','E','F','G','H' };
string position[8][8];
string input;
pair<int, int> objPos[2];

void init() {
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			position[i][j] = "" + col[j] + row[i];
}

bool isInRange(int y, int x) {
	return 0 <= y && y < 8 && 0 <= x && x < 8;
}

void moveObj(int dirIdx) {
	int next_k_posy = objPos[0].first + dy[dirIdx];
	int next_k_posx = objPos[0].second + dx[dirIdx];
	if (!isInRange(next_k_posy, next_k_posx))return;
	if (next_k_posy == objPos[1].first && next_k_posx == objPos[1].second) {
		int next_s_posy = objPos[1].first + dy[dirIdx];
		int next_s_posx = objPos[1].second + dx[dirIdx];
		if (!isInRange(next_s_posy, next_s_posx))return;
		objPos[1] = { next_s_posy,next_s_posx };
	}
	objPos[0] = { next_k_posy,next_k_posx };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	init();
	getline(cin, input);
	for (int i = 0, j = 0; i < 2; i++, j += 3) {
		string pos = input.substr(j, 2);
		objPos[i] = { pos[1] - '1',pos[0] - 'A' };
	}
	int N = stoi(input.substr(5));

	while (N--) {
		getline(cin, input);
		for(int i = 0;i<8;++i)
			if (dir[i] == input) { moveObj(i); break; }
	}
	
	for(int i =0;i<2;++i)
		cout << col[objPos[i].second] << row[objPos[i].first] << "\n";


	return 0;
}