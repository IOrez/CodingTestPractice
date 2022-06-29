#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Solution {
public:
    Solution();
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector<vector<int>> re;
        list<pair<int, int>> li;
        sort(people.begin(), people.end(), [&](vector<int>& v1, vector<int>& v2)->bool {
            if (v1[1] < v2[1])
                return true;
            else if (v1[1] == v2[1] && v1[0] < v2[0])
                return true;
            else
                return false;
        });


        for (size_t i = 0; i < people.size(); ++i)
        {
            int hi = people[i][0], ki = people[i][1];
            int cnt = 0;
            bool bCheck = false;
            auto iter = li.begin();
            for (; iter != li.end(); ++iter)
            {
                if (iter->first >= hi)
                {
                    cnt++;
                    if (cnt > ki) 
                    {
                        bCheck = true;
                        break;
                    }
                }
            }

            if (!bCheck)
                li.push_back({ hi,ki });
            else
                li.insert(iter, { hi,ki });
        }

        for (auto& item : li)
            re.push_back(vector<int>{item.first, item.second});
        return re;
    }

public:
    void Run()
    {
        this->reconstructQueue(people);
    }

public:
    vector<vector<int>> people;
};

Solution::Solution()
{
    people.push_back(vector<int>{6, 0});
    people.push_back(vector<int>{5, 0});
    people.push_back(vector<int>{4, 0});
    people.push_back(vector<int>{3, 2});
    people.push_back(vector<int>{2, 2});
    people.push_back(vector<int>{1, 4});
}