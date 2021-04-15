
// 474. Ones and Zeroes

class Solution {
public:
    pair<int, int> count(string str) {
        int num0 = 0;
        int num1 = 0;
        
        int len = str.size();
        for (int i = 0; i < len; i++) {
            if (str[i] == '0') {
                num0 ++;
            } else if (str[i] == '1') {
                num1 ++;
            }
        }
        
        return make_pair(num0, num1);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty()) {
            return 0;
        }
        
        // assert(m > 0 && n > 0);
        
        int len = strs.size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][0] = 0;
        for (int k = 1; k <= len; k++) {
            pair<int, int> tmp = count(strs[k - 1]);
            int num0 = tmp.first;
            int num1 = tmp.second;
            
            for (int j = n; j >= num1; j--) {
                for (int i = m; i >= num0; i--) {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1) ;
                }
            }
        }
        
        return dp[m][n];

    }   
};
