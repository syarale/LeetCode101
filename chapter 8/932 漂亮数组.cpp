
// 932. Beautiful Array

class Solution {
public:
    vector<int> getBeautiful(int n, unordered_map<int, vector<int> >& hash) {
        vector<int> ret;
        if (hash.find(n) != hash.end()) {
            return hash[n];
        }
        
        if (n < 3) {
            for (int i = 1; i <= n; i++) {
                ret.push_back(i);
            }
            hash[n] = ret;
            return ret;
        }
        
        int n1 = (n + 1) / 2;
        int n2 = n / 2;
        
        vector<int> ret1 = getBeautiful(n1, hash);
        vector<int> ret2 = getBeautiful(n2, hash);
        
        for (int i = 0; i < ret1.size(); i++) {
            ret1[i] = 2 * ret1[i] - 1;
        }
        
        for (int i = 0; i < ret2.size(); i++) {
            ret2[i] = 2 * ret2[i];
        }
        
        ret.insert(ret.end(), ret1.begin(), ret1.end());
        ret.insert(ret.end(), ret2.begin(), ret2.end()); 
        return ret;
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> ret;
        if (N < 3) {
            for (int i = 1; i <= N; i++) {
                ret.push_back(i);
            }
            return ret;
        }
        
        unordered_map<int, vector<int> > hash;
        ret = getBeautiful(N, hash);
        return ret;
    }
};

