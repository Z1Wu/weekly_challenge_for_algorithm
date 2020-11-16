#include "../common.h"

class Solution {
public:
    vector<vector<string>> res;
    vector<int> v;
    bool ok(int x, int y) {
        for(int i = 0; i < x; i++) {
            int j = v[i];
            if( (abs(i - x) == abs(j - y)) || 
                (y == j)
            ) {
                return false;
            }
        }
        return true;
    }
    void help(int x, int n) {
        if( x == n ) {
            // solution
            vector<string> cur_res(
                n, string(n, '.')
            );
            for(int i = 0; i < n; i++) {
                cur_res[i][v[i]] = 'Q';
            }
            res.push_back(cur_res);
        }
        else {
            for(int i = 0; i < n; ++i) {
                if(!ok(x, i)) {
                    continue;
                }
                v[x] = i;
                help(x + 1, n);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        v = vector<int>(n, 0);
        help(0, n);
        return res;
    }
};

int main() {
    
}