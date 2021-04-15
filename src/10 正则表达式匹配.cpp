
// 10. Regular Expression Matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        
        vector<vector<bool> > dp(sLen + 1, vector<bool> (pLen + 1, false));
        dp[0][0] = true;
        
        for (int j = 1; j <= pLen; j++) {
            if (p[j - 1] == '*') {
                if (j - 2 < 0) {
                    dp[0][j] = false;
                } else {
                    dp[0][j] = dp[0][j - 2]
                }
                
            } else {
                dp[0][j] = false;
            }
        }
        
        for (int i = 1; i <= sLen; i++) {
            dp[i][0] = false;
        }
        
        
        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= pLen; j++) {
                
                if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                } 
                
                if (p[j - 1] == '*') {
                    if (j - 2 < 0) {
                        dp[i][j] = false;
                        continue;
                    } 
                    
                    dp[i][j] = dp[i][j - 2];
                    
                    if (p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - 2] || dp[i - 1][j];
                    }
                    
                } else {
                    if (s[i - 1] == p[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        return dp[sLen][pLen];

    }
}; 
