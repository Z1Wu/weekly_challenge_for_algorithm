#include "../common.h"

class Solution {

public:
#ifdef SOL1
    // 去重方式，对于重复的元素，这些重复的元素的不重复的组成方式就是这些元素的个数
    // 比如 [1, 1, 1] 实际上就是只有选择 [1], [1, 1], [1,1,1] 三种方式
    // 所以对于每一个元素，选择的方案就是 0->num_of_ele，其中 0 代表不选这个元素。
    vector<vector<int>> res;
    vector<int> cur_res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 如何去除重复
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target);
        return res;
    }
    void solve(vector<int>& candi, int pos, int target){
        if(target == 0) {
            // solution
            res.push_back(cur_res);
       } else if (pos < candi.size()){
           int num = 0;
           int tmp = candi[pos];
           while(pos < candi.size() && candi[pos] == tmp) {
                pos ++;
                num ++;
           }
           for(int i = 0; i <= num; i++) {
               if (target - i * tmp < 0) {
                   // 剪枝
                   break;
               }
               for(int j = 0; j < i; j ++) {
                   cur_res.push_back(tmp);
               }
               solve(candi, pos, target - i * tmp);
               for(int j = 0; j < i; j ++) {
                   cur_res.pop_back();
               }
           }
       }
    }
#endif

};

int main() {

}