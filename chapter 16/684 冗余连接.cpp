
// 684. Redundant Connection 

class UF {
private:
    vector<int> id;
public:
    UF(int n) : id(n) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    void connect(int x, int y) {
        id[find(x)] = id[find(y)];
        return;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        UF uf(len + 1);

        if (edges.empty() || len == 1) {
            return vector<int> {-1, -1};
        }
        
        for (int i = 0; i < len ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (uf.isConnected(u, v)) {
                return edges[i];
            } else {
                uf.connect(u, v);
            }
        }

        return vector<int> {-1, -1};
    }
};
