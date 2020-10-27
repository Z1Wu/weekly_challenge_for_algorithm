#include "../common.h"
#define SOLUTION2

class Solution {
public:
#ifdef SOLUTION1
    int numTrees(int n) {
        if(n == 0) {
            return 0;
        }
        // 计算能构建的子树的数目
        // 需要注意计算 dp 数组的顺序
        // dp(m, n) = sum([dp(m, k) * dp(k + 1, n) for k in range(m, n + 1)])
        // n + 2, n + 2 数组, 最外圈的 padding 用来减少
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i = 1; i < n + 2; i++) { // 初始化数组
            for(int j = 1; j < n + 2; j++) {
                if(i >= j) {
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n + 2; i++) { // 边界元素
            dp[0][i] = 1;
            dp[i][0] = 1;
            dp[i][n + 1] = 1;
            dp[n + 1][i] = 1;
        }
        
        for(int l = 2; l <= n; l++) { // 长度
            for(int i = 1; i <= n - l + 1; i++) { // 起始元素
                // dp[i][i + l] += dp[i + 1][i + l - 1] + dp[i][i + l - 2]; // 
                int b = i, e = i + l - 1;
                // cout << b << "," << e << endl;
                for(int k = b; k <= e; k++) { // 间隔元素选取
                    // cout << b << "," << k - 1 << " * " <<  k + 1 << "," << e << endl;
                    dp[b][e] += (dp[b][k - 1] * dp[k + 1][e]);
                }
            }
        }
        // for(auto vec : dp) {
        //     for(auto e : vec) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }

        return dp[1][n];
    }
#endif
#ifdef SOLUTION2
    int numTrees(int n) {
        // 注意到上上面的 dp 数组中，影响每个元素的值的只有序列的长度，也就是说 (1, 2, 3) 和 (4, 5, 6) 能
        // 够组成的二叉搜索树的数目其实是一样的，所以没有必要用二维数组来存储这个 dp 问题
        // dp(n): 长度为 n 的序列能组成的二叉树数目
        // dp(n) = sum[dp(i) * dp(n - i - 1) for i in range(n)]
        // dp[0], dp[1] = 0
        if( n <= 1) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) { // 对每一种序列长度
            for(int j = 0; j <= i - 1; j++) { // 左子树的序列的长度 0 -> (i - 1)
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
#endif
};

int main() {
    int n = 3;
    cout << (Solution().numTrees(n)) << endl;
}