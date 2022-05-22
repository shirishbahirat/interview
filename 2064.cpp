#include <iostream>
#include <vector>
#include <numeric>

//Title: Minimized Maximum of Products Distributed to Any Store

using namespace std;

class Solution {
public:

    bool feasible(int n,  vector<int>& quantities, int products)
    {
        int product = 1;
        int total = 0;

        for (int i = 0; i < quantities.size(); ++i)
        {
            total += quantities[i];

            if (total > n)
            {
                total = quantities[i];
                product += 1;

                if (product > products)
                {
                    return false;
                }
            }
        }

        return true;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {

    int left = *max_element(quantities.begin(), quantities.end());

    int right = reduce(quantities.begin(), quantities.end());

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (feasible(mid, quantities, n))
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
