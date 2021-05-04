
// 547. Number of Provinces

class Solution {
public:
    void dfsTranvers(vector<vector<int>>& isConnected, int i, int j) {
        // assert(isConnected[i][j] == 1);
        isConnected[i][j] = 0;
        vector<int> direction {-1, 0, 1, 0, -1};
        for (int k = 0; k <= direction.size() - 2; k++) {
            int x = i + direction[k];
            int y = j + direction[k + 1];
            int row = isConnected.size();
            int col = isConnected[0].size();
            
            if (0 <= x && x < row && 0 <= y && y < col && isConnected[x][y] == 1) {
                dfsTranvers(isConnected, x, y);
            } 
        }
        
        return;     
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) {
            return 0;
        }
        
        int row = isConnected.size();
        int col = isConnected[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isConnected[i][j] == 0) {
                    continue;
                }
                
                count++;
                dfsTranvers(isConnected, i, j);
            }
        }
        
        return count;
    }
}; 
