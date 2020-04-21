#include <iostream>
#include <string.h>
using namespace std;


#define MIN(x,y) (((x)<=(y))? (x):(y))

unsigned int Point[26][26];
unsigned int DP[26][26];
unsigned int P[26][26];

void floyd(int N)
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			DP[i][j] = Point[i][j];

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				unsigned long long distance = DP[k][j];
				distance += DP[i][k];
				int min = MIN(DP[i][j], distance);
				if (min != DP[i][j])
				{
					P[i][j] = k;
					DP[i][j] = min;
				}
			}
}

void findPath(int sP,int eP)
{
	if (P[sP][eP] != 0)
	{
		findPath(sP, P[sP][eP]);
		cout << (char)(P[sP][eP] + 'A')<<endl;
		findPath(P[sP][eP], eP);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(Point, -1, sizeof(Point));
	for (int i = 0; i < 26; ++i) { Point[i][i] = 0; }



	int N,M;
	cin >> N >> M;
	while (M--)
	{
		char p1, p2;
		unsigned int weight;
		cin >> p1 >> p2 >> weight;
		p1 -= 'A';
		p2 -= 'A';
		Point[p1][p2] = weight;
		Point[p2][p1] = weight;
	}
	char start, end;
	cin >> start >> end;
	floyd(N);
	cout << (int)DP[start-'A'][end-'A']<<endl;
	cout << start << endl;
	findPath(start - 'A', end - 'A');
	cout << end << endl;
	return 0;
}