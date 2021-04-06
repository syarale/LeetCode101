// 51. N-Queens

class Solution {
public:
    void dfs(vector<int>& curr, int i, int n,
             vector<bool>& colUsed, vector<bool>& leftDiag, vector<bool>& rightDiag, 
             vector<vector<int> >& res) {
        
        for (int j = 0; j < n; j++) {
            if (colUsed[j] || leftDiag[i - j + n - 1] || rightDiag[i + j]) {
                continue;
            }
            
            colUsed[j] = true;
            leftDiag[i - j + n - 1]= true;
            rightDiag[i + j]= true;
            curr.push_back(j);
            
            if (i == n - 1) {
                res.push_back(curr);
            } else {
                dfs(curr, i + 1, n, colUsed, leftDiag, rightDiag, res);
            }
            
            leftDiag[i - j + n - 1]= false;
            rightDiag[i + j] = false;
            colUsed[j] = false; 
            curr.pop_back();
        }
        
        return;
    }
    
    vector<string> transferToStr(vector<int> location) {
        vector<string> res;
        int len = location.size();
        for (int i = 0; i < len; i++) {
            int loc = location[i];
            string tmp = "";
            for (int j = 0; j < len; j++) {
                if (j == loc) {
                    tmp += "Q";
                } else {
                    tmp += ".";
                }
            }
            res.push_back(tmp);
        }
        
        return res;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> curr;
        vector<vector<int> > res;
        
        vector<bool> colUsed(n, false);
        vector<bool> leftDiag(2 * n - 1, false);
        vector<bool> rightDiag(2 * n - 1, false);
        
        dfs(curr, 0, n, colUsed, leftDiag, rightDiag, res);
        
        vector<vector<string> > queens;
        for (int i = 0; i < res.size(); i++) {
            vector<string> tmp = transferToStr(res[i]);
            queens.push_back(tmp);
        }
        
        return queens;
    }
};
