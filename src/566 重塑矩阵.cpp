
// 566. Reshape the Matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) {
            return nums;
        }
        
        int row = nums.size();
        int col = nums[0].size();
        
        if (r <= 0 || c <= 0 || row * col != r * c) {
            return nums;
        }
        
        
        vector<vector<int> > matrix(r, vector<int> (c, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int newi = 0;
                int newj = 0;
                int k = i * col + j + 1;
                
                if (k % c == 0) {
                    newi = k / c - 1;
                    newj = c - 1;
                } else {
                    newi = k / c;
                    newj = k % c - 1;
                }
                
                matrix[newi][newj] = nums[i][j];
            }
        }
        
        return matrix;

    }
};
