#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; ++i)
            if (ratings[i] < ratings[i + 1])
                candys[i + 1] = candys[i] + 1;

        int ans = candys[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
                candys[i] = max(candys[i], candys[i + 1] + 1);
            ans += candys[i];
        }

        return ans;
    }
};