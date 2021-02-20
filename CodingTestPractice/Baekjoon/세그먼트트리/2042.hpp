#include <iostream>
#include <vector>
using namespace std;

using vll = vector<long long>;
int N, M, K, Size = 1;


long long init(vll& v, int node) {
	long long lval = 0, rval = 0;
	if (node * 2 >= Size)return v[node];
	lval = init(v, node * 2);
	rval = init(v, node * 2 + 1);

	v[node] = lval + rval;
	return v[node];
}

void update(vll& v, int node, long long dif) {
	while (node != 0) {
		v[node] += dif;
		node /= 2;
	}
}

long long findSum(vll& v, int s, int e) {
	long long lval = v[s], rval = v[e];
	if (s == e)return lval;
	while (s+1 < e) {
		if (s % 2 != 1)lval += v[s + 1];
		if (e % 2 == 1)rval += v[e - 1];
		s /= 2;
		e /= 2;
	}
	return lval + rval;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;
	
	while (true) {
		Size *= 2;
		if (N <= Size)break;
	}
	Size *= 2;
	vll v(Size);
	int start = Size / 2, end = Size / 2 + N;
	for (int i = 0; i < N; ++i)
		cin >> v[start + i];

	init(v, 1);

	long long t, a, b;
	for (int i = 0; i < M + K; ++i) {
		cin >> t >> a >> b;
		switch (t) {
		case 1:
			update(v, start + a - 1, b - v[start + a - 1]);
			break;
		case 2:
			cout << findSum(v, start + a - 1, start + b - 1)<<'\n';
			break;
		}
	}

	return 0;
}