#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> collection;
vector<char> s;
vector<char> picked;

void solution(int pivot ,int N)
{
	if (picked.size() == N)
	{
		string str;
		int check_vowel = 0,check_consonant=0;		
		for (auto ch : picked)
		{
			switch (ch)
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				check_vowel++; break;
			default:
				check_consonant++; break;
			}
			str.push_back(ch);
		}
		if (check_vowel >= 1 && check_consonant >= 2)
			collection.push_back(str);
	}
	else
	{
		for (int i = pivot; i < s.size(); ++i)
		{
			picked.push_back(s[i]);
			solution(i + 1, N);
			picked.pop_back();
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int L, C;
	cin >> L >> C;
	cin.ignore();
	for (int i = 0; i < C; ++i)
	{
		char ch;
		cin >> ch;
		cin.ignore();
		s.push_back(ch);
	}
	sort(s.begin(), s.end());
	solution(0, L);
	for (auto& str : collection)
		cout << str << endl;

	return 0;
}