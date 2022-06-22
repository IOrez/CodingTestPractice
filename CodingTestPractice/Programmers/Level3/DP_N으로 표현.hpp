#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 8

int minDepth = MAX + 1;
void dfs(int depth, int target, int N, int current)
{
    if (depth > MAX || minDepth < depth)
        return;
    if (target == current)
    {
        minDepth = min(depth, minDepth);
        return;
    }

    int operand = 0;
    for (int i = 1; i <= MAX - depth; ++i)
    {
        operand = operand * 10 + N;
        dfs(depth + i, target, N, current + operand);
        dfs(depth + i, target, N, current - operand);
        dfs(depth + i, target, N, current * operand);
        dfs(depth + i, target, N, current / operand);
    }
    return;
}

int solution(int N, int number) {
    dfs(0, number, N, 0);
    return (minDepth > MAX) ? -1 : minDepth;
}