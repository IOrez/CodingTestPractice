#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;



int solution(vector<int> a) {
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < a.size(); ++i)
        pq.push({ -a[i],i });
    int Min = numeric_limits<int>::max();
    int Max = numeric_limits<int>::min();
    int i = 0;
    while (!pq.empty()) {
        auto [number,idx] = pq.top();
        pq.pop();
        if (Min > idx || idx > Max) {
            answer++;
            Min = min(Min, idx);
            Max = max(Max, idx);
        }
    }

    return answer;
}