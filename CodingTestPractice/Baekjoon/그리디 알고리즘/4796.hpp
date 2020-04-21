#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		static unsigned int i = 0;
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)break;

		int a = (V / P) * L;
		int b = (V % P) < L ? V % P : L;

		int result = a+b;
		cout << "Case " << ++i << ": " << result << endl;
	}

	return 0;
}