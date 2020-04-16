#include <iostream>
#include <string>;
using namespace std;

void solution(int N,string&s,bool& result) 
{
	int val;
	s.push_back('4');
	val = stoi(s);
	if (val > 1000) { s.pop_back(); return;}
	if (N % val == 0) { result = true; return; }
	solution(N, s, result);
	s.pop_back();
	s.push_back('7');
	val = stoi(s);
	if (N % val == 0) { result = true; return; }
	solution(N, s, result);
	s.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	string s;
	cin >> n;
	bool result = false;
	solution(n, s, result);
	if (result)cout << "YES";
	else cout << "NO";
	return 0;
}