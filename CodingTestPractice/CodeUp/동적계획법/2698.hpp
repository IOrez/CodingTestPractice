#include <iostream>

using namespace std;

int N;
int solution(int n, char start, char temp, char end)
{
	if (n == 0)return 0;
	int result = 0;
	result += solution(n - 1, start, temp, end);
	cout << n << " : " << start << "->" << temp << '\n';
	result += 1;
	result += solution(n - 1, end, temp, start);
	cout << n << " : " << temp << "->" << end << '\n';
	result += 1;
	result += solution(n - 1, start, temp, end);
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	cout << solution(N, 'A', 'B', 'C');
	return 0;
}