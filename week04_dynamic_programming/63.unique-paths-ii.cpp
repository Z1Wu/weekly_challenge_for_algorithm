#include "../common.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<int> dp(n + 1, 0);
        if(obstacleGrid[0][0] != 1) {
            dp[1] = 1;
        } else {
            return 0;
        }
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++ ) {
                // cout << i << ", "<< j << endl;
                if( !(i == 1 && j == 1)) {
                    // dp[j] = dp[j] + dp[j - 1]
                    // dp[j] 代表上一行的值，也就是 dp[i - 1][j]
                    // d[j - 1] 代表从右边得到，dp[i][j - 1]
                    if(obstacleGrid[i - 1][j - 1] ==  1) {
                        dp[j] = 0;
                    } else {
                        dp[j] += dp[j - 1]; 
                    }
                }
            }
        }
        return dp[n];
    }
};