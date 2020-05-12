#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Table[1000][1000];
enum class Type
{
	OO,EO,OE,EE
};


void func_OO_OE(int N,int M)
{
	int sPosY = 0;
	string res;
	auto func = [&](string& str, char ch, int cnt)
	{
		for (int i = 0; i < cnt; ++i)
			str.push_back(ch);
	};
	while (sPosY + 1 < N)
	{
		func(res, 'R', M - 1);
		func(res, 'D', 1);
		func(res, 'L', M - 1);
		func(res, 'D', 1);
		sPosY += 2;
	}
	func(res, 'R', M - 1);
	cout << res;
};

void func_EO(int N, int M)
{
	int sPosX = 0;
	string res;
	auto func = [&](string& str, char ch, int cnt)
	{
		for (int i = 0; i < cnt; ++i)
			str.push_back(ch);
	};
	while (sPosX + 1 < M)
	{
		func(res, 'D', N - 1);
		func(res, 'R', 1);
		func(res, 'U', N - 1);
		func(res, 'R', 1);
		sPosX += 2;
	}
	func(res, 'D', N - 1);
	cout << res;
}

void func_EE(int N, int M,int MinposX,int MinposY)
{
	string res;
	string revres;
	
	int sPosX = 0, sPosY = 0;
	int ePosX = M-1, ePosY = N-1;
	auto func = [&](string& str, char ch, int cnt)
	{
		for (int i = 0; i < cnt; ++i)
			str.push_back(ch);
	};
	while (ePosY - sPosY > 1)
	{
		if (sPosY + 1 < MinposY)
		{
			func(res, 'R', M - 1);
			func(res, 'D', 1);
			func(res, 'L', M - 1);
			func(res, 'D', 1);
			sPosY += 2;
		}

		if (ePosY - 1 > MinposY)
		{
			func(revres, 'R', M - 1);
			func(revres, 'D', 1);
			func(revres, 'L', M - 1);
			func(revres, 'D', 1);
			ePosY -= 2;
		}
	}

	while (ePosX - sPosX > 1)
	{
		if (sPosX + 1 < MinposX)
		{
			func(res, 'D', 1);
			func(res, 'R', 1);
			func(res, 'U', 1);
			func(res, 'R', 1);
			sPosX += 2;
		}

		if (ePosX - 1 > MinposX)
		{
			func(revres, 'D',1);
			func(revres, 'R',1);
			func(revres, 'U',1);
			func(revres, 'R',1);
			ePosX -= 2;
		}
	}
	if (sPosX + 1 == MinposX)
	{
		func(res, 'D', 1);
		func(res, 'R', 1);
	}
	else
	{
		func(res, 'R', 1);
		func(res, 'D', 1);
	}
	reverse(revres.begin(), revres.end());
	res.append(revres);
	cout << res;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	Type type;
	cin >> N >> M;
	
	

	int min = 9999999;
	int min_row = -1;
	int min_col = -1;


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> Table[i][j];
			if ((i + j) % 2 && min > Table[i][j])
			{
				min = Table[i][j];
				min_row = i;
				min_col = j;
			}

		}
	if (N % 2 == 0 && M % 2 == 0)type = Type::EE;
	else if (N % 2 == 1 && M % 2 == 0)type = Type::OE;
	else if (N % 2 == 0 && M % 2 == 1)type = Type::EO;
	else if (N % 2 == 1 && M % 2 == 1)type = Type::OO;
	switch (type)
	{
	case Type::OO:
	case Type::OE:
		func_OO_OE(N, M);
		break;
	case Type::EO:
		func_EO(N, M);
		break;
	case Type::EE:
		func_EE(N, M, min_col,min_row);
		break;
	}
	
	return 0;
}