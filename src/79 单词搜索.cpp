// 79. Word Search

class Solution {
public:
    bool dfs(vector<vector<char> >& board, int i, int j, int depth,
             string word, vector<vector<bool> >& used) {
         
         // assert(board[i][j] == word[depth]); 
        if (board[i][j] != word[depth]) {
            return false;   // cann't happen.
        }
 
        // assert(!board.empty() && !used.empty()) and ....
        if (depth == word.size() - 1) {
            return true;
        }
        
          
        used[i][j] = true;
        
        int row = board.size();
        int col = board[0].size();
        vector<int> direction {-1, 0, 1, 0, -1};
        for (int k = 0; k < direction.size() - 1; k++) {
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if (0 <= x && x < row && 0 <= y && y < col 
                && board[x][y] == word[depth + 1] && used[x][y] == false) {
                    
                if (dfs(board, x, y, depth + 1, word, used)) {
                    used[i][j] = false;
                    return true;
                }
            }
        }
        
        used[i][j] = false;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
            return false;
        } 
        
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > used(row, vector<bool> (col, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                
                if (dfs(board, i, j, 0, word, used)) {
                    return true;
                }
            }
        }
        
        return false;

    }
};
