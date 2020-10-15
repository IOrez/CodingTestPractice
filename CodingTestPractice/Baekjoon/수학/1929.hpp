#include <iostream>

using namespace std;
int M, N;
bool Notprime[1000001];
void solution() {
	Notprime[1] = true;
	for (int i = 2; i <= N; ++i) {
		if (Notprime[i])continue;
		for(int j = 2;j*j<=i&&!Notprime[i];++j)
			if (i % j == 0)
				Notprime[i] = true;
		if(!Notprime[i])
			for (int k = i+i; k <= N; k += i)
				Notprime[k] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	solution();
	for (int i = M; i <= N; ++i)
		if (!Notprime[i])cout << i << '\n';
	return 0;
}