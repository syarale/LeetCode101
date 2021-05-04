
// 310. Minimum Height Trees

// Multi-BFS
class Solution {
public:
    void transferEdges(const vector<vector<int>>& edges, vector<unordered_set<int> >& connection) {
        if (edges.empty()) {
            return;
        }
        
        int len = edges.size();
        
        // assert(connection.size() == len);
        // assert(connection[0].size() == len);
        for (int i = 0; i < len; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            connection[x].insert(y);
            connection[y].insert(x);
        }
        
        return;
    }
    
    int multiBFS(int n, vector<unordered_set<int> >& connection, vector<int>& root) {
        // assert...
        
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            root.push_back(0);
            return 1;
        }

        queue<int> leafNodes;
        for (int i = 0; i < n; i++) {
            if (connection[i].size() == 1) {
                leafNodes.push(i);
            }
        }
        
        int visitedNum = 0;
        int level = 0;
        while (!leafNodes.empty()) {
            int num = leafNodes.size();
            level ++;
            
            if (visitedNum >= n - 2) {
                while (!leafNodes.empty()) {
                    int tmp = leafNodes.front();
                    leafNodes.pop();
                    root.push_back(tmp);
                }
                
                break;
            }
            
            while (num > 0) {
                int currNode = leafNodes.front();
                leafNodes.pop();
                visitedNum ++;
                num --;
                
                unordered_set<int>::iterator it = connection[currNode].begin();
                int connNode = *it;
                
                connection[currNode].clear();
                connection[connNode].erase(currNode);
                if (connection[connNode].size() == 1) {
                    leafNodes.push(connNode);
                }
            }
            
        }
        
        return level;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // assert...
        vector<int> root;
        
        vector<unordered_set<int> > connection(n);
        transferEdges(edges, connection);
        
        int height = multiBFS(n, connection, root);
        return root;
    }
};




// 310. Minimum Height Trees


// BFS: over time
//class Solution {
//public:
//    void transferEdges(const vector<vector<int>>& edges, vector<vector<int>>& connection) {
//        if (edges.empty()) {
//            return;
//        }
//        
//        int len = edges.size();
//        
//        // assert(connection.size() == len);
//        // assert(connection[0].size() == len);
//        for (int i = 0; i < len; i++) {
//            int x = edges[i][0];
//            int y = edges[i][1];
//            connection[x][y] = 1;
//            connection[y][x] = 1;
//        }
//        
//        return;
//    }
//    
//    int bfs(int i, const vector<vector<int> >& connection) {
//        // assert...
//        
//        int level = 0;
//        queue<int> nodes;
//        vector<bool> used(connection.size(), false); 
//        
//        nodes.push(i);
//        used[i] = true;
//        
//        while (!nodes.empty()) {
//            int num = nodes.size();
//            if (num == 0) {
//                break;
//            }
//            
//            while (num > 0) {
//                int curr = nodes.front();
//                nodes.pop();
//                num--;
//                   
//                for (int j = 0; j < connection[0].size(); j++) {
//                    if (j != curr && connection[curr][j] == 1 && !used[j]) {
//                        nodes.push(j);
//                        used[j] = true;
//                    }
//                }         
//            }
//            
//            level ++;
//        }
//        
//        return level;
//    }
//    
//    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//        // assert...
//        vector<int> root;
//        
//        vector<vector<int> > connection(n, vector<int> (n, 0));
//        transferEdges(edges, connection);
//        
//        
//        int minHeight = n + 1;
//        
//        for (int i = 0; i < n; i++) {
//            int path = bfs(i, connection);
//            
//            if (path == minHeight) {
//                root.push_back(i);
//            } else if (path < minHeight) {
//                minHeight = path;
//                root.clear();
//                root.push_back(i);
//            }
//        }
//        
//        return root;
//    }
//};





// DFS: over time

//class Solution {
//public:
//    void transferEdges(const vector<vector<int>>& edges, vector<vector<int>>& connection) {
//        if (edges.empty()) {
//            return;
//        }
//        
//        int len = edges.size();
//        
//        // assert(connection.size() == len);
//        // assert(connection[0].size() == len);
//        for (int i = 0; i < len; i++) {
//            int x = edges[i][0];
//            int y = edges[i][1];
//            connection[x][y] = 1;
//            connection[y][x] = 1;
//        }
//        
//        return;
//    }
//    
//    int dfs(int i, vector<bool>& used, const vector<vector<int>>& connection) {
//        // assert...
//         
//        int height = 1;
//        int maxPath = 0;
//        int len = connection.size();
//        
//        used[i] = true;
//        for (int j = 0; j < len; j++) {
//            if (i != j && connection[i][j] == 1 && !used[j]) {
//                maxPath = max(maxPath, dfs(j, used, connection));
//            } 
//        }
//        
//        used[i] = false;
//        height = maxPath + 1;
//        return height;
//    }
//    
//    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//        // assert...
//        vector<int> root;
//        vector<bool> used(n, false); 
//        vector<vector<int> > connection(n, vector<int> (n, 0));
//        transferEdges(edges, connection);
//        
//        
//        int minHeight = n + 1;
//        
//        for (int i = 0; i < n; i++) {
//            int path = dfs(i, used, connection);
//            
//            if (path == minHeight) {
//                root.push_back(i);
//            } else if (path < minHeight) {
//                minHeight = path;
//                root.clear();
//                root.push_back(i);
//            }
//        }
//        
//        return root;
//    }
//};
