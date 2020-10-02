#include <iostream>
#include <utility>
using namespace std;
int N;

bool table[128][128];

template<typename T>
struct p :public std::pair<T,T> {
public:
	p(T first, T second) {
		this->first = first;
		this->second = second;
	}
public:
	void operator +=(p<T> obj) {
		this->first += obj.first;
		this->second += obj.second;
	}
};

p<int> solution(int LTy,int LTx,int RBy,int RBx) {
	p<int> cnt(0,0);
	bool type = table[LTy][LTx],check=true;
	for (int y = LTy; y <= RBy&&check; ++y)
		for (int x = LTx; x <= RBx&&check; ++x) 
			check = (type == table[y][x]);

	if (check) {
		if (type) return p<int>(1, 0);
		else return p<int>(0, 1);
	}
	cnt += solution(LTy, LTx, (LTy+RBy) / 2, (LTx+RBx) / 2);
	cnt += solution(LTy, (LTx + RBx) / 2 + 1, (LTy + RBy) / 2, RBx);
	cnt += solution((LTy + RBy) / 2 + 1, LTx, RBy, (LTx + RBx) / 2);
	cnt += solution((LTy + RBy) / 2 + 1, (LTx + RBx) / 2 + 1, RBy, RBx);
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x) 
			cin >> table[y][x];
	p<int> result = solution(0, 0, N - 1, N - 1);
	cout << result.second << '\n';
	cout << result.first << '\n';
	return 0;
}