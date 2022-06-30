#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        int mid = n / 2;
        for (int i = 0; i < n; ++i)
            steps += abs(nums[i] - nums[mid]);

        return steps;
    }

};