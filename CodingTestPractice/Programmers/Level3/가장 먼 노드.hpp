#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int dist[20001];

void dfs(vector<vector<int>>& edgeTable, int srcNode, int depth)
{
    for (int i = 0; i < edgeTable[srcNode].size(); ++i)
    {
        int dstNode = edgeTable[srcNode][i];
        if (dist[dstNode] > depth)
        {
            dist[dstNode] = depth;
            dfs(edgeTable, dstNode, depth + 1);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> edgeTable(n + 1);
    int i = 0;
    for (i = 1; i <= n; ++i)
        dist[i] = numeric_limits<int>().max();

    for (i = 0; i < edge.size(); ++i)
    {
        edgeTable[edge[i][0]].push_back(edge[i][1]);
        edgeTable[edge[i][1]].push_back(edge[i][0]);
    }

    for (i = 0; i <= n; ++i)
        sort(edgeTable[i].begin(), edgeTable[i].end());

    dist[1] = 0;
    dfs(edgeTable, 1, 1);

    int ans_val = 0;
    int ans_cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ans_val == dist[i])
            ans_cnt++;
        else if (ans_val < dist[i])
        {
            ans_cnt = 1;
            ans_val = dist[i];
        }
    }

    return ans_cnt;
}