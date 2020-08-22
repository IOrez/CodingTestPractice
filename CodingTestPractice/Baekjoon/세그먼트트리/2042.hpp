#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M, K, Type, n1, n2, pivot;
using vll = vector<long long>;

long long makeTree(vll& v,int node) {
	if (node >= pivot + N)return 0;
	v[node] += makeTree(v, 2 * node) + makeTree(v, 2 * node + 1);
	return v[node];
}

void updateTree(vll& v, int node,int val) {
	v[node] = val;
	while (node != 1) {
		if (node % 2 == 0)
			v[node / 2] = v[node] + v[node + 1];
		else
			v[node / 2] = v[node] + v[node - 1];
		node /= 2;
	}
}

long long findSum(vll& v, int start, int end) {
	if (start == end)return v[start];
	long long sSum = v[start], eSum = v[end];
	while (start + 1 < end) {
		if (start % 2 == 0)
			sSum += v[start + 1];
		if (end % 2 == 1)
			eSum += v[end - 1];

		start /= 2; end /= 2;
	}
	return sSum + eSum;
}
void segmentTree(vll& v,int type, int n1, int n2)
{
	switch (type) {
	case 1:
		M--;
		updateTree(v, pivot + n1 - 1, n2);
		break;
	case 2:
		K--;
		cout<< findSum(v, pivot + n1 - 1, pivot + n2 - 1)<<'\n';
		break;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;
	int height = 0;
	while (true) {
		if (pow(2, height) > N)break;
		height++;
	}
	vll v(pow(2, height + 1));
	pivot = (int)pow(2, height);
	for (int i = pivot;i<pivot+N ; ++i)
		cin >> v[i];
	makeTree(v, 1);
	while (M != 0 || K != 0) {
		cin >> Type >> n1 >> n2;
		segmentTree(v, Type, n1, n2);
	}
	return 0;
}