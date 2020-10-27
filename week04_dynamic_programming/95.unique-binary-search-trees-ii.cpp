#include "../common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    // record result duplicate the ans
    // map<
    
    vector<TreeNode*> helper(int b, int e) {
        vector<TreeNode*> res;
        if(b == e) {
            TreeNode* root = new TreeNode(b, NULL, NULL);
            res.push_back(root);
            return res;
        } else if (b > e) {
            res.push_back(NULL);
            return res;
        }
        for(int i = b; i <= e;  i++) {
            // TreeNode* root = new TreeNode(b, NULL, NULL);
            auto lcs = helper(b, i - 1);
            auto rcs = helper(i + 1, e);
            for(auto lc : lcs) {
                for (auto rc : rcs) {
                    TreeNode* root = new TreeNode(i, lc, rc);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        // using reursive
        auto res = helper(1, n);
        return res;
    }
};