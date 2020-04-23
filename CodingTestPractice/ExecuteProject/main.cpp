#include <iostream>
#include <vector>

using namespace std;

int	 tap[100];
bool isPluged[100];

void solution(vector<int>& vec,int idx,int N,int K, int* cnt)
{
	if (isPluged[vec[idx]])return;
	static int i = 0;
	if (i<N)
	{
		tap[i] = vec[idx];
		isPluged[tap[i]] = true;
		i++;
		return;
	}

	(*cnt)++;
	int maxDistance = 0;
	int id = 0;
	for (int i = 0; i < N; ++i)
	{
		unsigned int distance = -1;
		for (int j = idx + 1; j < K; ++j)
			if (vec[j] == tap[i]){
				distance = j - idx;
				break;
			}
		
		if (maxDistance < distance)
		{
			maxDistance = distance;
			id = i;
		}
	}

	isPluged[tap[id]] = false;
	tap[id] = vec[idx];
	isPluged[tap[id]] = true;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,K,cnt=0;
	cin >> N >> K;
	vector<int> v(K);
	for (int i = 0; i < K; ++i)cin >> v[i];
	for (int i = 0; i < K; ++i)solution(v, i, N,K, &cnt);
	cout << cnt;
	return 0;
}