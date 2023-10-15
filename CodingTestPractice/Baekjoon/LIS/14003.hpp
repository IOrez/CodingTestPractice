#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v;

void Solution()
{
	vector<int> vtmp;
	vector<int> vIdx(v.size());
	for (int i = 0; i < v.size(); i++)
	{
		int target = v[i];
		int idx = 0;
		auto iter = lower_bound(vtmp.begin(), vtmp.end(), target);
		if (iter != vtmp.end())
		{
			*iter = target;
			idx = iter - vtmp.begin();
		}
		else
		{
			vtmp.push_back(target);
			idx = vtmp.size() - 1;
		}

		vIdx[i] = idx;
	}

	stack<int> st;
	cout << vtmp.size() << '\n';
	int len = vtmp.size() - 1;
	for (int i = vIdx.size() - 1; i >= 0; i--)
	{
		if (vIdx[i] == len)
		{
			st.push(v[i]);
			len--;
		}
	}

	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
}

int main()
{
	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	Solution();
	
	return 0;
}