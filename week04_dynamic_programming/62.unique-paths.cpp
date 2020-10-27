#include "../common.h"
class Solution {
public:
    // 空间复杂度可以是 O(n) 
    // 只能向下走 / 向右走
    // dp[m][n]: 从 (1, 1) 到达 (m, n) 的独立路径数
    // dp(m, n) = dp(m - 1, n) + dp(m, n - 1) 
    // dp(1, 1) = 1 
    // 注意 dp 的顺序
    // 也有非 dp 的解法
    int uniquePaths(int m, int n) {

        // if(m == 0 || n == 0) { 
        //     return 0;
        // }
        // vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        // bool f = 1;
        // dp[f][1] = 1;
        // for(int i = 1; i < m + 1; i++) {
        //     for(int j = 1; j < n + 1; j++ ) {
        //         // cout << i << ", "<< j << endl;
        //         if( !(i == 1 && j == 1)) {
        //             // dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //             dp[f][j] = dp[!f][j] + dp[f][j - 1];
        //         }
        //     }
        //     f = !f;
        // }
        // return dp[!f][n];

        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        vector<int> dp(n + 1, 0);
        bool f = 1;
        dp[1] = 1;
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++ ) {
                // cout << i << ", "<< j << endl;
                if( !(i == 1 && j == 1)) {
                    // dp[j] = dp[j] + dp[j - 1]
                    // dp[j] 代表上一行的值，也就是 dp[i - 1][j]
                    // d[j - 1] 代表从右边得到，dp[i][j - 1]
                    dp[j] += dp[j - 1]; 
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int m = 3, n = 7;
    cout << Solution().uniquePaths(m, n) << endl;
}