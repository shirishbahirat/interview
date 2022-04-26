#include <iostream>
#include <vector>

//Title: Search a 2D Matrix

using namespace std;

class Solution {
public:

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
