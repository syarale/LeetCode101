
// 934. Shortest Bridge

class Solution {
public:
    void dfs(vector<vector<int> >& A, int i, int j, queue<pair<int, int> >& points) {
        // assert....
        int row = A.size();
        int col = A[0].size();
        
        if (i < 0 || i >= row || j < 0 || j >= col || A[i][j] != 1) {
            return;
        }
        
        A[i][j] = 2;
        points.push(pair<int, int> (i, j));
        vector<int> direction {-1, 0, 1, 0, -1};
        for (int k = 0; k < direction.size() - 1; k++) {
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if (0 <= x && x < row && 0 <= y && y < col && A[x][y] == 1) {
                dfs(A, x, y, points);
            }
        }
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        if (A.empty()) {
            return -1;
        }
        
        int row = A.size();
        int col = A[0].size();
        bool flipped = false;
        queue<pair<int, int> > points;
        
        for (int i = 0; i < row; i++) {
            if (flipped) {
                break;
            }
            for (int j = 0; j < col; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, points);
                    flipped = true;
                    break;
                }
            }
        } 


        int level = 0;
        vector<int> direction {-1, 0, 1, 0, -1};
        while (!points.empty()) {
            int numPoints = points.size();
            level ++;

            while (numPoints > 0) {
                pair<int, int> tmp = points.front();
                points.pop();
                
                int xLoc = tmp.first;
                int yLoc = tmp.second;

                for (int k = 0; k < direction.size() - 1; k++) {
                    int x = xLoc + direction[k];
                    int y = yLoc + direction[k + 1];
                    
                    if (0 <= x && x < row && 0 <= y && y < col) {

                        if (A[x][y] == 2) {
                            continue;
                        }
                        
                        if (A[x][y] == 1) {
                            return level  - 1;
                        }
                        
                        if (A[x][y] == 0) {
                            A[x][y] = 2;
                            points.push({x, y});
                        }
                    }
                }
                
                numPoints --;
            }  
        }
        
        return 0;

    }
}; 
