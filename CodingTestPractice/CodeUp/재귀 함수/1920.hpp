#include <iostream>
#include <string>
using namespace std;

string output("0");
void solution(int n)
{
	if (n == 0)return;
	int mo = n % 2;
	output.insert(output.begin(), (char)(mo + '0'));
	solution(n / 2);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	if (n != 0)output.clear();
	solution(n);
	cout << output;
	return 0;
}