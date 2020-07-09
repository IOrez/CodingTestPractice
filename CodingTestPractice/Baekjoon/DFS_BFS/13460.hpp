#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int table[11][11];

typedef struct pos
{
	int _y;
	int _x;

	bool operator < (pos& obj)
	{
		if (this->_y < obj._y)return true;
		else if (this->_y == obj._y && this->_x < obj._x)return true;
		else return false;
	}

	bool operator == (pos& obj)
	{
		return this->_y == obj._y && this->_x == obj._x;
	}

	bool operator != (pos& obj)
	{
		return this->_y != obj._y || this->_x != obj._x;
	}
}Pos;

typedef struct step
{
	Pos _redPos;
	Pos _bluePos;

	bool operator < (step& obj)
	{
		if (this->_redPos < obj._redPos)return true;
		else if (this->_redPos == obj._redPos && this->_bluePos < obj._bluePos)return true;
		else return false;
	}

}Step;

priority_queue<pair<int, int> > pq;
unordered_map<int, Step> umap;

int key;
int solution()
{
	int stepCnt = -1;
	Step s;
	
	while (!pq.empty())
	{
		stepCnt = -pq.top().first;
		s = umap[pq.top().second];
		stepCnt++;
		if (stepCnt > 10)return -1;
		Pos rPos = s._redPos;
		Pos bPos = s._bluePos;

		rPos = s._redPos;
		bPos = s._bluePos;
		if (s._redPos._y >= s._bluePos._y)
		{
			while (table[bPos._y - 1][bPos._x] != -1 && table[bPos._y - 1][bPos._x] != 3)
				bPos._y--;
			table[bPos._y][bPos._x] = 2;
			while (table[rPos._y - 1][rPos._x] != -1 && table[rPos._y - 1][rPos._x] != 2 && table[rPos._y - 1][rPos._x] != 3)
				rPos._y--;
			table[rPos._y][rPos._x] = 1;
		}
		else if( s._redPos._y<=s._bluePos._y)
		{
			while (table[rPos._y - 1][rPos._x] != -1 && table[rPos._y - 1][rPos._x] != 3)
				rPos._y--;
			table[rPos._y][rPos._x] = 1;
			while (table[bPos._y - 1][bPos._x] != -1 && table[bPos._y - 1][bPos._x] != 1 && table[bPos._y - 1][bPos._x] != 3)
				bPos._y--;
			table[bPos._y][bPos._x] = 2;
		}

		if (table[rPos._y - 1][rPos._x] == 3 && table[rPos._y + 1][rPos._x] != 2)return stepCnt;
		else if (table[bPos._y - 1][bPos._x] != 3&&(s._redPos!=rPos||s._bluePos!=bPos))
		{
			umap.insert({ ++key,{rPos,bPos} });
			pq.push({ -stepCnt,key });
		}

		table[bPos._y][bPos._x] = 0;
		table[rPos._y][rPos._x] = 0;
		//***************************************************************************************************
		rPos = s._redPos;
		bPos = s._bluePos;
		if (s._redPos._y >= s._bluePos._y)
		{
			while (table[rPos._y + 1][rPos._x] != -1 && table[rPos._y + 1][rPos._x] != 3)
				rPos._y++;
			table[rPos._y][rPos._x] = 1;
			while (table[bPos._y + 1][bPos._x] != -1 && table[bPos._y + 1][bPos._x] != 1 && table[bPos._y + 1][bPos._x] != 3)
				bPos._y++;
			table[bPos._y][bPos._x] = 2;
		}
		else if(s._redPos._y <= s._bluePos._y)
		{
			while (table[bPos._y + 1][bPos._x] != -1 && table[bPos._y + 1][bPos._x] != 3)
				bPos._y++;
			table[bPos._y][bPos._x] = 2;
			while (table[rPos._y + 1][rPos._x] != -1 && table[rPos._y + 1][rPos._x] != 2 && table[rPos._y + 1][rPos._x] != 3)
				rPos._y++;
			table[rPos._y][rPos._x] = 1;
		}

		if (table[rPos._y + 1][rPos._x] == 3&&table[rPos._y-1][rPos._x]!=2)return stepCnt;
		else if (table[bPos._y + 1][bPos._x] != 3 && (s._redPos != rPos || s._bluePos != bPos))
		{
			umap.insert({ ++key,{rPos,bPos} });
			pq.push({ -stepCnt,key });
		}

		table[bPos._y][bPos._x] = 0;
		table[rPos._y][rPos._x] = 0;
		
	
		rPos = s._redPos;
		bPos = s._bluePos;
		if (s._redPos._x >= s._bluePos._x)
		{
			while (table[bPos._y][bPos._x - 1] != -1 && table[bPos._y][bPos._x - 1] != 3)
				bPos._x--;
			table[bPos._y][bPos._x] = 2;
			while (table[rPos._y][rPos._x - 1] != -1 && table[rPos._y][rPos._x - 1] != 2 && table[rPos._y][rPos._x - 1] != 3)
				rPos._x--;
			table[rPos._y][rPos._x] = 1;
		}
		else if (s._redPos._x <= s._bluePos._x)
		{
			while (table[rPos._y][rPos._x - 1] != -1 && table[rPos._y][rPos._x - 1] != 3)
				rPos._x--;
			table[rPos._y][rPos._x] = 1;
			while (table[bPos._y][bPos._x - 1] != -1 && table[bPos._y][bPos._x - 1] != 1 && table[bPos._y][bPos._x - 1] != 3)
				bPos._x--;
			table[bPos._y][bPos._x] = 2;
		}

		if (table[rPos._y][rPos._x - 1] == 3 && table[rPos._y][rPos._x+1] != 2)return stepCnt;
		else if (table[bPos._y][bPos._x - 1] != 3 && (s._redPos != rPos || s._bluePos != bPos))
		{
			umap.insert({ ++key,{rPos,bPos} });
			pq.push({ -stepCnt,key });
		}

		table[bPos._y][bPos._x] = 0;
		table[rPos._y][rPos._x] = 0;
		//***************************************************************************************************
		rPos = s._redPos;
		bPos = s._bluePos;
		if (s._redPos._x >= s._bluePos._x)
		{
			while (table[rPos._y][rPos._x+1] != -1 && table[rPos._y][rPos._x+1] != 3)
				rPos._x++;
			table[rPos._y][rPos._x] = 1;
			while (table[bPos._y][bPos._x+1] != -1 && table[bPos._y][bPos._x+1] != 1 && table[bPos._y][bPos._x+1] != 3)
				bPos._x++;
			table[bPos._y][bPos._x] = 2;
		}
		else if (s._redPos._x <= s._bluePos._x)
		{
			while (table[bPos._y][bPos._x+1] != -1 && table[bPos._y][bPos._x+1] != 3)
				bPos._x++;
			table[bPos._y][bPos._x] = 2;
			while (table[rPos._y][rPos._x+1] != -1 && table[rPos._y][rPos._x+1] != 2 && table[rPos._y][rPos._x+1] != 3)
				rPos._x++;
			table[rPos._y][rPos._x] = 1;
		}

		if (table[rPos._y][rPos._x + 1] == 3 && table[rPos._y][rPos._x-1] != 2)return stepCnt;
		else if (table[bPos._y][bPos._x + 1] != 3 && (s._redPos != rPos || s._bluePos != bPos))
		{
			umap.insert({ ++key,{rPos,bPos} });
			pq.push({ -stepCnt,key });
		}

		table[bPos._y][bPos._x] = 0;
		table[rPos._y][rPos._x] = 0;
		umap.erase(pq.top().second);
		pq.pop();
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	Step start;
	int N, M;
	cin >> N >> M; cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);
		for (int j = 0; j < M; ++j)
		{
			if (input[j] == '#')table[i][j] = -1;
			else if (input[j] == '.')table[i][j] = 0;
			else if (input[j] == 'R')
			{
				table[i][j] = 0;
				start._redPos = Pos{ i,j };
			}
			else if (input[j] == 'B')
			{
				table[i][j] = 0;
				start._bluePos = Pos{ i,j };
			}
			else if (input[j] == 'O')
				table[i][j] = 3;
		}
	}
	
	umap.insert({ ++key,start });
	pq.push({ -0,key });
	int result = solution();
	cout << result;
	return 0;
}