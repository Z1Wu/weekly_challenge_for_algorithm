#include "../common.h"


class Solution {
public:

#ifdef SOLUTION1
    int maxProduct(vector<int>& nums) {
        // vector<int> dp(nums.size(), 0);
        // dp_max[i] 代表以 i'th 元素结尾的最大子数组，
        // 这里确定需要一个辅助数组来存储以 i'th 结尾的最小子数组 dp[min]
        // 应为
        // dp_max[i] = max(A[i], dp_min[i - 1] * A[i], dp_max[i - 1] * A[i]) 

        int p_min = nums[0];
        int p_max = nums[0];
        int r = p_max;
        for(int i = 1; i < nums.size(); i++) {
            int t_min = p_min;
            int t_max = p_max;
            p_min = min(t_min * nums[i], min(t_max * nums[i], nums[i]));
            // 最大值也可能出现在 p_min 和 nums[i] < 0 的情况下。
            p_max = max(t_min * nums[i], max(t_max * nums[i], nums[i])); 
            r = max(p_max, r);
        }
        
        return r;
    }
#endif

#ifdef SOLUTION2
    // 在数组中没有0的情况下，可以得到规律 ，最大子数组积肯定是数组的前缀数组 / 或者后缀数组
    // 计算出所有的前缀积 和 后缀积，取最大的那个。
    int maxProduct(vector<int>& nums) {
        
    }
#endif

};


