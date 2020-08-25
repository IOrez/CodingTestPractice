#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

using tdii = tuple<int, int, int,int>;
int N;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int val = x1 * y2 + x2 * y3 + x3 * y1;
	val -= y1 * x2 + y2 * x3 + y3 * x1;
	return val;
}
int comp(tdii& obj1, tdii& obj2) {

	long long lval = 1LL*get<1>(obj1) * get<0>(obj2);
	long long rval = 1LL*get<1>(obj2) * get<0>(obj1);
	if (lval != rval) return lval < rval;
	if (get<2>(obj1) != get<2>(obj2))return get<2>(obj1) < get<2>(obj2);
	return get<3>(obj1) < get<3>(obj2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<tdii> v(N);
	for (int i = 0; i < N; ++i)
		cin >> get<3>(v[i]) >> get<2>(v[i]);

	sort(v.begin(), v.end());

	for (int i = 1; i < N; ++i) {
		get<0>(v[i]) = (get<3>(v[i]) - get<3>(v[0]));
		get<1>(v[i]) = (get<2>(v[i]) - get<2>(v[0]));
	}
	sort(v.begin() + 1, v.end(),comp);

	stack<tdii> st;
	int i = 0;
	while (i < N) {
		while (st.size() >= 2) {
			auto point = st.top(); st.pop();
			int x1 = get<3>(st.top()), y1 = get<2>(st.top());
			int x2 = get<3>(point), y2 = get<2>(point);
			int x3 = get<3>(v[i]), y3 = get<2>(v[i]);
			if (ccw(x1, y1, x2, y2, x3, y3)>0) {
				st.push(point);
				break;
			}
		}
		st.push(v[i++]);
	}
	cout << st.size();

	return 0;
}