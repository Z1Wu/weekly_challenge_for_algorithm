#include "../common.h"

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cur_sum = 0;
        int ret = INT32_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if( cur_sum >= 0) {
                cur_sum += nums[i];
            } else {
                cur_sum = nums[i];
            }
            ret = max(cur_sum, ret);
        }
        return ret;
    }
};