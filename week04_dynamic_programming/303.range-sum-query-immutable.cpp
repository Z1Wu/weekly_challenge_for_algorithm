#include "../common.h"

class NumArray {
public:
    
    NumArray(vector<int>& nums) {
        accmu_arr.push_back(0);
        for(auto e : nums) 
            accmu_arr.push_back(accmu_arr.back() + e);
    }
    
    int sumRange(int i, int j) {
        return accmu_arr[j + 1] - accmu_arr[i];
    }

private:
    vector<int> accmu_arr;
};
int main() {
    vector<int> nums;
    INPUT_ARRAY(nums);

    return 0;
}