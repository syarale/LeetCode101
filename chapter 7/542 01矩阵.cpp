
// 542. 01 Matrix
 
class Solution {
public:
    const int MAX = 10001;
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        if (matrix.empty()) {
            vector<vector<int> > tmp;
            return tmp;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > dis(row, vector<int> (col, MAX));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                    continue;
                } 
                
                if (i > 0) {
                    dis[i][j] = min(dis[i][j], dis[i - 1][j] + 1);
                }
                
                if (j > 0) {
                    dis[i][j] = min(dis[i][j], dis[i][j - 1] + 1);
                }
            }
        }
        
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                    continue;
                }
                
                if (i < row - 1) {
                    dis[i][j] = min(dis[i][j], dis[i + 1][j] + 1);
                }
                
                if (j < col - 1) {
                    dis[i][j] = min(dis[i][j], dis[i][j + 1] + 1);
                }
            }
        }
        
        return dis;
        
    }
};
