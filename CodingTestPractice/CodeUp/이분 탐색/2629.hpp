#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

#define BOUNDARY 1000000

void binarySearch(vector<pair<int, int>> arr,int left, int right,const int& p, int& index)
{
	if (left > right) { index = left; return; }
	int pivot = (left + right) / 2;
	if (p + arr[pivot].second > BOUNDARY) binarySearch(arr, left, pivot - 1, p, index);
	else if (p + arr[pivot].second < BOUNDARY) binarySearch(arr, pivot + 1,right, p, index);
	else { index = pivot; return; }
}


int main()
{
	int n,p;
	scanf("%d%d", &n,&p);
	vector<pair<int,int>> arr(n);

	for (int i = 0; i < n; ++i)
	{
		int x, y, p;
		scanf("%d%d%d", &x, &y, &p);
		arr[i] = { x * x + y * y,p };
	}

	sort(begin(arr), end(arr));

	for (auto i = 1; i < n; ++i)
		arr[i].second += arr[i - 1].second;

	bool isOk = true;
	int  pivot = n / 2;
	int idx = 0;
	binarySearch(arr, 0, n - 1, p, idx);
	if (idx >= n || isOk < 0) isOk = false;
	else if (p + arr[idx].second < BOUNDARY)isOk = false;

	if (!isOk)printf("-1\n");
	else {
		printf("%.3f\n", sqrt(arr[idx].first));
	}

	return 0;
}