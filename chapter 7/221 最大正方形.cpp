
// 221. Maximal Square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        int maxSide = 0;
        vector<vector<int> > dp(row, vector<int> (col, 0));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                
                maxSide = max(maxSide, dp[i][j]);
            }
        }
        
        return maxSide * maxSide;

    }
}; 
