
// 64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> dp(col, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < col; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        
        for (int i = 1; i < row; i++) {
            dp[0] = dp[0] + grid[i][0];
            
            for (int j = 1; j < col; j++) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        
        return dp[col - 1];
    }
};
