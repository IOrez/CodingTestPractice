#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int  testCase;
int num;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> testCase;
	while (testCase--) {
		vector<int> v;
		cin >> num;
		int score,Sum=0;
		for (int i = 0; i < num; ++i)
		{
			cin >> score;
			v.push_back(score);
			Sum += score;
		}
		double avg = (double)Sum / num;
		int cnt = 0;
		for (auto& i : v)
			if(i>avg)
				cnt++;
		cout << fixed << setprecision(3) << (double)cnt/num*100 << "%" << '\n';
	}
	return 0;

}