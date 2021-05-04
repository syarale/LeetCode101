
//  46. Permutations

class Solution {
public:
    void dfs (vector<int>& nums, int depth, vector<int>& path, 
              vector<bool>& used, vector<vector<int> >& res) {
        
        int len = nums.size();
        if (nums.empty()) {
            return;
        }
        
        if (depth == len) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < len; i++) {
            if (used[i]) {
                continue;
            }
            
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, depth + 1, path, used, res);
            path.pop_back();
            used[i] = false;
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size();
        
        if (nums.empty()) {
            return res;
        }
        
        vector<bool> used(len, false);
        vector<int> path;
        
        dfs(nums, 0, path, used, res);
        return res;
    }
};
