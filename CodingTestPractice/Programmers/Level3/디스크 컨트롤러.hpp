#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    priority_queue<pair<int, int>> pq;
    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] < b[0])
            return true;
        else if (a[0] == b[0] && a[1] < b[1])
            return true;
        return false;
        });

    pq.push(make_pair(-jobs[0][1], -jobs[0][0]));
    while (!pq.empty())
    {
        auto job = pq.top();
        pq.pop();

        job.first *= -1;
        job.second *= -1;   

            if (job.second < curTime)
                answer += curTime - job.second;
            else
                curTime = job.second;
        answer += job.first;
        curTime += job.first;

        static int i = 1;
        for (; i < jobs.size(); ++i)
        {
            if (jobs[i][0] > curTime && !pq.empty())
                break;
            pq.push(make_pair(-jobs[i][1], -jobs[i][0]));
        }
    }

    answer /= jobs.size();
    return answer;
}