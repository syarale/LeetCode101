
// 77. Combinations

class Solution {
public:
    void dfs(vector<int>& curr, int depth, int minPos, int n, int k,
             vector<vector<int> >& res) {
        
        if (depth == k) {
            res.push_back(curr);
            return;
        }
        
        int extend = k - depth;
        for (int i = minPos; i <= (n - extend + 1); i++) {
            
            curr.push_back(i);
            dfs(curr, depth + 1, i + 1, n, k, res);
            curr.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        int len = n;
//        vector<bool> used(len + 1, false);
//        used[0] = true;
        
        vector<int> curr;
        vector<vector<int> > res;
        
        dfs(curr, 0, 1, n, k, res);
        return res; 

    }
};
