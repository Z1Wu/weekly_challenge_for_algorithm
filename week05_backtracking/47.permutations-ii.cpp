#include "common.h"

class Solution {
public:
    // 如何处理重复的问题
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int pos, vector<int>& cur, vector<bool>& used) {
        if(pos == nums.size()) {
            res.push_back(cur);
        } else {
            for(int i = 0; i < nums.size(); i++) {
                // 确定 pos 位置的元素
                if(used[i]) {
                    continue;
                }
                if(i > 0  && nums[i] == nums[i - 1] && !used[i - 1]) {
                    // 去除重复元素
                    continue;
                }
                cur.push_back(nums[i]);
                used[i] = true;
                dfs(nums, pos + 1, cur, used);
                cur.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // permutation with same elements

        // sort
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        dfs(nums, 0, cur, used);
        return res;
    }
};

int main() {
     vector<int> nums{
        1,1,2
    };
    // cout << nums[0] << nums[1] << nums[2] << endl;
    auto res = Solution().permuteUnique(nums);
    for(auto line : res) {
        for(auto e: line ) {
            cout << e << " ";
        }
        cout << endl;
    }
    
}