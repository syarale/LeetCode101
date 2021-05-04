// 695.Max Area of Island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int maxArea = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> direction{-1, 0, 1, 0, -1};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                
                int area = 1;
                grid[i][j] = 0;
                stack<pair<int, int> > island;
                island.push(pair<int, int> (i, j));
                while (!island.empty()) {
                    pair<int, int> tmp = island.top();
                    island.pop();
                    
                    int xLoc = tmp.first;
                    int yLoc = tmp.second; 
                    for (int k = 0; k <= direction.size() - 2; k++) {
                        int x = xLoc + direction[k];
                        int y = yLoc + direction[k + 1];
                        if (0 <= x && x < row && 0 <= y && y < col && grid[x][y] == 1) {
                            area++;
                            grid[x][y] = 0;
                            island.push(pair<int, int> (x, y));
                        }
                    }
                    
                }
                
                maxArea = max(maxArea, area);
                
            }
        }
        
        return maxArea;
    }
}; 
