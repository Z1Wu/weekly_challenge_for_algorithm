class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m , n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        # ret = 0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if(text1[i - 1] == text2[j - 1]):
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        for l in dp[1:]:
            print(l[1:])
        str = self.get_str(text1, text2, m, n, dp)
        print(str)
        return dp[m][n]
    
    def get_str(self, s1, s2, m, n, dp):
        ret = ""
        while(1):
            print(f"{m}, {n}")
            if m == 0 or n == 0:
                break
            if s1[m - 1] == s2[n - 1]:
                ret += s1[m - 1]
                m = m - 1
                n = n - 1
            else:
                if dp[m - 1][n] > dp[m][n - 1]:
                    m = m - 1
                else:
                    n = n - 1
        return ret[::-1]
    
    def longestCommonSubsequence_1(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        if m < n: # 保证 m 是大的
            return self.longestCommonSubsequence_1(text2, text1)
        
        dp = [[0] * (n + 1) for _ in range(2)] 
        f = 1
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[f][j] = dp[not f][j - 1] + 1
                else:
                    dp[f][j] = max(dp[not f][j], dp[f][j - 1])
            f = not f

        return dp[not f][n]
            



if __name__ == "__main__":
    text1 = "abcde"
    text2 = "ace" 
    print(Solution().longestCommonSubsequence_1(text1, text2))