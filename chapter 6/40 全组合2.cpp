
// 40. Combination Sum II

class Solution {
public:
    void dfs(vector<int>& candidates, int pos, int target, vector<int>& path,
             vector<vector<int> >& res) {
        // assert...
        
        int len = candidates.size();
        if (target == 0) {
            res.push_back(path);
            return;
        } 
        
        for (int i = pos; i < len; i++) {
            if (candidates[i] > target) {
                break;
            }
            
            if (i > pos && candidates[i] == candidates[i - 1] ) {
                continue;
            }
            
            path.push_back(candidates[i]);
            
            dfs(candidates, i + 1, target - candidates[i], path, res);
            
            path.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<int> path;
        vector<vector<int> > res;
        
        if (candidates.empty()) {
            return res;
        }
        
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, res);
        
        return res;

    }
}; 
