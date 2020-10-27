#include "../common.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n <= 2) return n;
        // dp[n] = dp[n - 1] + dp[n - 2]
        // 只需要使用前两个元素存储即可
        int dp[2] = {1, 2};
        bool flag = 0;
        for(int i = 3; i <= n; i++) {
            dp[flag] = dp[flag] + dp[!flag]; 
            flag = !flag;
        }
        return dp[!flag];
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().climbStairs(n) << endl;
  return 0;
}