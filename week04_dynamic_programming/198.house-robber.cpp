#include "../common.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // dp[n] = max(dp[n - 2] + nums[n], dp[n - 1])
        int dp[2] = {nums[0], max(nums[0], nums[1])};
        bool f = 0;
        for( int i = 3; i <= n; i++) {
            // cout << dp[0] << " " << dp[1] << endl;
            dp[f] = max(dp[f] + nums[i - 1], dp[!f]);
            f = !f;
        }
        return dp[!f];
    }
};

int main() {
    vector<int> nums;
    INPUT_ARRAY(nums);
    // for( auto e : nums) {
    //     cout << e << endl;
    // }
    cout << Solution().rob(nums) << endl;
    return 0;
}