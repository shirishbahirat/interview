#include <iostream>
#include <vector>

//Title: Valid Triangle Number

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 2; --i){
            int l = 0, r = i - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    count += r - l;
                    --r;
                }else{
                    ++l;
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();
    return 0;
}
