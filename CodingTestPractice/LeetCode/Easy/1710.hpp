#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](auto& a, auto& b)->bool {
            return a[1] > b[1];
            });

        int totUnits = 0;
        for (auto& box : boxTypes)
        {
            int remainBoxes = min(truckSize, box[0]);
            totUnits += remainBoxes * box[1];
            truckSize -= remainBoxes;
        }

        return totUnits;
    }
};