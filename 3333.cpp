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

        int part = start + (end - start) / 2;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            cout << mid << endl;

            if (nums[mid] == val)
                return val;

            if (mid < part)
                ans = nums[mid];
            else
                ans = nums[start];
                

            if (val > nums[mid])
            {
                start = mid + 1;
            }
            else if (val < nums[mid])
            {
                end = mid;
            }

        }

         return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    vector<int> nums = {2,5,7,12,17,19,22};

    cout << obj->ExactOrMin(nums, 22) << endl;

    return 0;
}
