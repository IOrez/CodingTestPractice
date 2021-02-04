#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

vector<tuple<int, int, int>> con;
vector<int> results;

int N,M,v1,v2,maxV2;



void solution() {
	int cur = 2*N;
	maxV2 = std::get<1>(con[0]);
	for (auto& obj : con) {
		auto [obj_v1, obj_v2, idx] = obj;
		if (obj_v1 >= cur)  continue; 
		if (maxV2 >= N&&maxV2-N>=obj_v2)continue; 
		cur = obj_v1;
		results.push_back(idx);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> v1 >> v2;
		if (v1 > v2)v2 += N;
		con.push_back({ v1,v2,i + 1 });
	}

	sort(con.begin(), con.end(), [=](tuple<int, int, int>& obj1, tuple<int, int, int>& obj2)->bool {
		auto [obj1_v1, obj1_v2, obj1_idx] = obj1;
		auto [obj2_v1, obj2_v2, obj2_idx] = obj2;
		if (obj1_v2 > obj2_v2)return true;
		else if (obj1_v2 == obj2_v2 && obj1_v1 < obj2_v1)return true;
		else return false;
	});

	solution();
	sort(results.begin(), results.end());
	for (auto& i : results)
		cout << i << ' ';
	return 0;
}