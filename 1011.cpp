#include <iostream>
#include <vector>

//Title: Capacity To Ship Packages Within D Days

using namespace std;

class Solution {
public:

    bool feasible(int capacity,  vector<int>& weights, int days)
    {
        int day = 1;
        int total = 0;

        for (int i = 0; i < weights.size(); ++i)
        {
            total += weights[i];

            if (total > capacity)
            {
                total = weight;
                day += 1;

                if (day > days)
                {
                    return false;
                }
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int left = *max_element(weights.begin(), weights.end());
        int right = *min_element(weights.begin(), weights.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (feasible(mid, weights, days))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;

    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();
    return 0;
}
