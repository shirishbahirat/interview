#include <iostream>
#include <vector>

//Title: Exact or Min

using namespace std;

class Solution
{
public:
    int ExactOrMin(vector<int> &nums, int val)
    {

        if (nums.size() == 0)
            return -1;

        int ans = -1;

        int start = 0;
        int end = nums.size();

        while (start > end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == val)
                return val;

            if (val > nums[mid])
                start = mid + 1;
            else if (val < nums[mid])
                end = mid;

        }



         return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();
    return 0;
}
