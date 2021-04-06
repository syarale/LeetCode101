
// 417. Pacific Atlantic Water Flow

class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& reach, int i, int j) {
        // assert(...);
        int row = heights.size();
        int col = heights[0].size();
        
        if (reach[i][j] == 1) {
            return;
        }
        
        reach[i][j] = 1;
        vector<int> direction {-1, 0, 1, 0, -1};
        for (int k = 0; k < direction.size() - 1; k++) {
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if (0 <= x && x < row && 0 <= y && y < col 
                 && heights[x][y] >= heights[i][j]) {
                 dfs(heights, reach, x, y);
            }
        }
        
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int> > res;
        
        if (heights.empty()) {
            return res;
        }
        
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int> > reachPac(row, vector<int> (col, 0));
        vector<vector<int> > reachAtl(row, vector<int> (col, 0));
        
        for (int i = 0; i < row; i++) {
            dfs(heights, reachPac, i, 0);
            dfs(heights, reachAtl, i, col - 1);
        }
        
        for (int j = 0; j < col; j++) {
            dfs(heights, reachPac, 0, j);
            dfs(heights, reachAtl, row - 1, j);
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (reachPac[i][j] == 1 && reachAtl[i][j] == 1) {
                    vector<int> tmp {i, j};
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }
}; 
