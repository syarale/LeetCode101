// 240. Search a 2D Matrix II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[row - 1][col - 1]) {
            return false;
        }
        
        int x = row - 1;
        int y = 0;
        
        while (x >= 0 && y < col) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                x--;
            } else {
                y++;
            }
        } 
        
        return false;
    }
};
