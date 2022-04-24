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
                cout << mid << endl;
                return 0;
            }

            if (target > nums[mid])
            {
                left = mid + 1;
            } 
            else if ( target < nums[mid])
            {
                right = mid;
            }

        }


    }

    int get_pivot(vector<int>& nums)
    {


        if (nums.empty())
        {
            return -1;
        }

        if (nums.size() < 2)
        {
            return 0;
        }

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i+1] < nums[0])
            {
                return i + 1;
            } 
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> arr = {4,5,6,7,0,1,2};


    Solution *obj = new Solution();

    int index = obj->search(arr, 7);

    return 0;
}
