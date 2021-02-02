#include <string>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 200

int group[SIZE];
int cnt;
void bfs(int i, int n, vector<vector<int>>& computers) {
    queue<int> que;
    group[i] = cnt;
    que.push(i);
    while (!que.empty()) {
        int idx = que.front(); que.pop();
        for (int j = 0; j < n; ++j) {
            if (!computers[idx][j] || group[j])continue;
            group[j] = cnt;
            que.push(j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        if (group[i])continue;
        cnt++;
        bfs(i, n, computers);
    }
    answer = cnt;
    return answer;
}