
// 130. Surrounded Regions

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, 
             vector<vector<bool> >& visited) {
        // assert...
        
        int row = board.size();
        int col = board[0].size();
        vector<int> direction {-1, 0, 1, 0, -1};
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O' 
            || visited[i][j]) {
            
            return;
        }
        
        visited[i][j] = true;
        for (int k = 0; k < direction.size() - 1; k++) {
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if (0 <= x && x < row && 0 <= y && y < col 
                && board[x][y] == 'O' && !visited[x][y]) {
                
                dfs(board, x, y, visited);
            }
        }
        
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool> (col, false));
        
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, i, 0, visited);
            }
            
            if (board[i][col - 1] == 'O' && !visited[i][col - 1]) {
                dfs(board, i, col - 1, visited);
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(board, 0, j, visited);
            }
            
            if (board[row - 1][j] == 'O' && !visited[row - 1][j]) {
                dfs(board, row - 1, j, visited);
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                    visited[i][j] = true;
                }
            }
        }
        
        return;
    }
};
