#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, M;
int posy, posx, d;

using vvi = vector<vector<int>>;

enum dir{
	North,
	East,
	South,
	West,
	MaxCount
};


tuple<int, int> Update(dir direction,int step) {
	int nposy = posy, nposx = posx;
	switch (direction) {
	case North: nposy -= step; break;
	case East: nposx += step; break;
	case South: nposy += step; break;
	case West: nposx -= step; break;
	}
	return { nposy,nposx };
}


int solution(vvi& v,vvi& ch) {
	int cnt = 0;
	while (true) {
		
		if (!ch[posy][posx]) {
			ch[posy][posx] = true;
			cnt++;
		}

		bool result = false;
		int di[4] = { 1,2,3,0 };
		for (int i = 0; i < dir::MaxCount&&!result; ++i) {
			dir tmpdir = (d - di[i]) < 0 ? (dir)((d- di[i])+dir::MaxCount) : (dir)(d- di[i]);
			auto [nposy, nposx] = Update(tmpdir,1);
			if (ch[nposy][nposx] == false && v[nposy][nposx] == 0) {
				posy = nposy;
				posx = nposx;
				d = tmpdir;
				result = true;
			}
		}

		if (!result) {
			dir backdir = (d - 2) < 0 ? (dir)((d - 2) + dir::MaxCount) : (dir)(d - 2);
			auto [nposy, nposx] = Update((dir)backdir, 1);
			if (v[nposy][nposx] == 1)
				break;
			else{
				posy = nposy;
				posx = nposx;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin >> posy >> posx >> d;
	vvi v(N, vector<int>(M));
	vvi ch(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];

	cout << solution(v, ch);


	return 0;
}