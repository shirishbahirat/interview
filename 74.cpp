#include <iostream>
#include <vector>

//Title: Search a 2D Matrix

using namespace std;

class Solution {
public:

    bool bin_search(vector<int>& nums, int left, int right, int target)
    {

        while (left <= right)
        {

            int mid = left + (right - left)/2;

            if (target == nums[mid])
            {
                return true;
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

                return false;
            }            

        }

        return false;

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    return 0;
}
