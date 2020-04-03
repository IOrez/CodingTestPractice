#include <iostream>
#include <vector>
using namespace std;


void unionFind(vector<int>& v, int A, int B)
{
	if (v[A] > v[B])v[A] = v[B];
	else v[B] = v[A];
}

bool is_same_parent(vector<int>& v,int& A, int& B)
{
	while (v[A] != A)A = v[A];
	while (v[B] != B)B = v[B];

	return A == B;
}

int parent(vector<int>& v, int i)
{
	while (v[i] != i) i = v[i];
	return i;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> country(N + 1);
	for (auto i = 1; i <= N; ++i)
		country[i] = i;

	while (M--)
	{
		int A, B;
		cin >> A >> B;
		if (!is_same_parent(country, A, B))
			unionFind(country, A, B);
	}
	for (auto i = 1; i <= N; ++i)
		cout << parent(country,i) << " ";
	cout << endl;

	country.clear();
	return 0;
}