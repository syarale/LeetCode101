
//  47. Permutations II

class Solution {
public:
    void dfs(vector<int>& nums, int depth, vector<int>& path, vector<bool>& used, 
             vector<vector<int> >& res) {
        
        int len = nums.size();
        if (depth == len) {
            for (int i = 0; i < path.size(); i++) {
                cout<<path[i]<<" ";
            }
            cout<<endl;
            res.push_back(path);
            return;
        } 
        
//        if (used[depth] || (depth > 0 && nums[depth] == nums[depth - 1] && !used[depth - 1])) {
//            return;
//        }
        
        for (int i = 0; i < len; i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            
            used[i] = true;
            path.push_back(nums[i]);
            
            dfs(nums, depth + 1, path, used, res);
            
            used[i] == false;
            path.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > res;
        vector<int> path;
        vector<bool> used(len, false);
        
        if (nums.empty()) {
           return res;
        } 
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, 0, path, used, res);
        cout<<"res.size(): "<<res.size()<<endl;
        return res;
    }
};
