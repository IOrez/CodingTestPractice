#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 60001
#define MOD 1000000007
int DP[MAX_SIZE];

int solution(int n) {
    int answer = 0;
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= n; ++i)
        DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;

    answer = DP[n];
    return answer;
}