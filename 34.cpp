#include <iostream>
#include <vector>

//Title: Find First and Last Position of Element in Sorted Array

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/

using namespace std;

class Solution
{
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


    vector<int> results = {-1, -1};

    vector<int> searchRange(vector<int>& nums, int target) {
     
   if (nums.size() == 1)
    {
        if (target == nums[0])
        {
           results[0] = 0;
           results[1] = 0;
           return results;
        }
        
        return results;
    }

    int idx = bin_search(nums, 0, nums.size() - 1, target);

    cout << idx << endl;

    if (idx != -1)
    {

        int idy = idx;

        while ((nums[idy] == target) && (idy > 0))
        {

            results[0] = idy;
            --idy;
        }

        idy = idx;

        while ((nums[idy] == target) && (idy < nums.size()))
        {

            results[1] = idy;
            ++idy;
        }


    }

     return results;   
    }
};


int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    vector<int> nums = {2,2};

    vector<int> results;

    results = obj->searchRange(nums, 2);

    cout << results[0] << endl;
    cout << results[1] << endl;

    return 0;
}
