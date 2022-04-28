#include <iostream>
#include <vector>

//Title:  Search in Rotated Sorted Array II

/*

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

 */

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

    bool search(vector<int>& nums, int target) {
        
        if (nums.size() == 1)
        {
            if (target == nums[0]) return true;

            return false;
        }

        int mid = get_pivot(nums);

        if (mid < 0)
            return false;




        int idm = mid;

        while ((idm > 0) && (nums[idm] == nums[mid]))
        {
            --idm;
        }


        int idx = bin_search(nums,0, idm, target);

        if (idx >= 0)
        {
            return true;
        }


        int idy = bin_search(nums, idm+1, nums.size() - 1, target);

        cout << "pivot " << idy << endl;

        if (idy >= idm+1)
        {
            return true;
        }

        return false;
    }
};


int main(int argc, char const *argv[])
{

    vector<int> arr = {0,1,2,2,2,2};

    Solution *obj = new Solution();

    int index = obj->search(arr, 2);

    cout << index << endl;

    return 0;
}
