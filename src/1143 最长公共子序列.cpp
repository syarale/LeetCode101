
// 1143. Longest Common Subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int> > dp(len1, vector<int> (len2, 0)); 
        
        if (text1.empty() || text2.empty()) {
            return 0;
        }
        
        if (text1[0] == text2[0]) {
            dp[0][0] = 1;
        } else {
            dp[0][0] = 0;
        }
        
        for (int j = 1; j < len2; j++) {
            if (text1[0] == text2[j] || dp[0][j - 1] == 1) {
                dp[0][j] = 1;
            }
        }
        
        for (int i = 1; i < len1; i++) {
            if (text1[i] == text2[0] || dp[i - 1][0] == 1) {
                dp[i][0] = 1;
            }
        }
        
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                    if (text1[i] == text2[j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
            }
                
        }
        
        return dp[len1 - 1][len2 - 1];
    }
}; 
