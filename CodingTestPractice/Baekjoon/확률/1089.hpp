#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int N;

int arr[10][5][3] = {
	{
		{1,1,1},
		{1,0,1},
		{1,0,1},
		{1,0,1},
		{1,1,1}		//0
	},
	{
		{0,0,1},
		{0,0,1},
		{0,0,1},
		{0,0,1},
		{0,0,1}		//1
	},
	{
		{1,1,1},
		{0,0,1},
		{1,1,1},
		{1,0,0},
		{1,1,1}		//2
	},
	{
		{1,1,1},
		{0,0,1},
		{1,1,1},
		{0,0,1},
		{1,1,1}		//3
	},
	{
		{1,0,1},
		{1,0,1},
		{1,1,1},
		{0,0,1},
		{0,0,1}		//4
	},
	{
		{1,1,1},
		{1,0,0},
		{1,1,1},
		{0,0,1},
		{1,1,1}		//5
	},
	{
		{1,1,1},
		{1,0,0},
		{1,1,1},
		{1,0,1},
		{1,1,1}		//6
	},
	{
		{1,1,1},
		{0,0,1},
		{0,0,1},
		{0,0,1},
		{0,0,1}		//7
	},
	{
		{1,1,1},
		{1,0,1},
		{1,1,1},
		{1,0,1},
		{1,1,1}		//8
	},
	{
		{1,1,1},
		{1,0,1},
		{1,1,1},
		{0,0,1},
		{1,1,1}		//9
	}
};
int table[5][40];

char input;

bool match(int py, int px, int number) {
	bool result = true;
	for (int i = py; i < py + 5&&result; ++i) {
		for (int j = px; j < px + 3&&result; ++j) {
			if (arr[number][i - py][j - px] - table[i][j] < 0)
				result = false;
		}
	}
	return result;
}

double solution() {
	
	vector<double> v;
	for (int i = 0; i < N; ++i) {
		int py = 0, px = 3 * i + i;
		vector<int> con;
		int cal = 0;
		for (int j = 0;j < 10; ++j) {
			if (match(py, px, j))
				con.push_back(j);
		}

		if (con.empty()) return -1;
		else {
			for (auto& i : con)
				cal += i;

			v.push_back((double)cal / con.size());
		}
	}

	double ans = 0.0f;
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
		ans += *iter * pow(10, iter - v.rbegin());
	}
	
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);	
	cin >> N; cin.ignore();
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4*N-1; ++j) {
			cin >> input;
			if (input == '#')
				table[i][j] = 1;
		}
	}
	cout << fixed<<setprecision(6)<<solution();
	
	return 0;
}
