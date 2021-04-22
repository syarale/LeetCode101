
// 304. Range Sum Query 2D - Immutable


class NumMatrix {
private:   
    vector<vector<int> > sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // assert(!matrix.empty());
        // assert(!matrix[0].empty());
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        sum.resize(row + 1, vector<int> (col + 1, 0));
        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < col + 1; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] 
                            + matrix[i - 1][j - 1];
            } 
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1]
                - sum[row2 + 1][col1] + sum[row1][col1]);

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */ 
