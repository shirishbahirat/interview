#include <iostream>
#include <vector>


//Title: Search in Rotated Sorted Array

using namespace std;

class Solution {
public:

    int bin_search(vector<int>& nums, int left, int right, int target)
    {

        while (left <= right)
        {

            int mid = left + (right - left)/2;

            if (target == nums[mid])
            {
                return mid;
            }

            if (target > nums[mid])
            {
                left = mid + 1;
            } 
            else if ( target < nums[mid])
            {
                right = mid;
            }

            if (left == right)
            {
                if (nums[left] == target)
                    return left;

                return -1;
            }            

        }

        return -1;

    }

    int get_pivot(vector<int>& nums)
    {

        if (nums.empty())
        {
            return -1;
        }

        int i = 0;

        for (i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i+1] < nums[0])
            {
                return i + 1;
            } 
        }

        return i;
    }

    int search(vector<int>& nums, int target) {

        int mid = get_pivot(nums);

        if (mid < 0)
            return -1;

        if (nums.size() == 1)
        {
            if (target == nums[0]) return 0;

            return -1;
        }

        int idx = bin_search(nums,0, mid - 1, target);

        if (idx >= 0)
        {
            return idx;
        }

        int idy = bin_search(nums, mid, nums.size() - 1, target);

        if (idy >= mid)
        {
            return idy;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{

    vector<int> arr = {4,5,6,7,0,1,2};

    Solution *obj = new Solution();

    int index = obj->search(arr, 2);

    cout << index << endl;

    return 0;
}
