
// 48. Rotate Image

class Solution {
public:
    void rotateEdge(vector<vector<int> >& matrix, int k, int len) {
        // assert(k < matrix.size() / 2);
        // assert(len == matrix.size() - k * 2);
        for (int l = 0; l < len - 1; l++) {
            int tmp = matrix[k][k + l];
            matrix[k][k + l] = matrix[k + len - 1 - l][k];
            matrix[k + len - 1 - l][k] = matrix[k + len - 1][k + len - 1 - l];
            matrix[k + len - 1][k + len - 1 - l] = matrix[k + l][k + len - 1];
            matrix[k + l][k + len - 1] = tmp;
        }
        
        return;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        
        int n = matrix.size();
        // assert(matrix[0].size() == n);
        
        for (int k = 0; k < (n / 2); k++) {
            int len = n - k * 2;
            rotateEdge(matrix, k, len);
        }
        
        return;
    }
};
