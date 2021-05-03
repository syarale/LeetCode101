
// 647. Palindromic Substrings

 class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len <= 1) {
            return len;
        }

        int count = 0;
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for (int i = 0; i <= len - 2; i++) {
            dp[i][i] = true;
            count++;

            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            } else {
                dp[i][i + 1] = false;
            }
        }

        dp[len - 1][len - 1] = true;
        count ++;

        for (int l = 2; l < len; l++) {
            for (int i = 0; i < len - l; i++) {
                if (s[i] == s[i + l] && dp[i + 1][i + l - 1]) {
                    dp[i][i + l] = true;
                    count ++;
                    continue;
                }

                dp[i][i + l] = false;
            }
        }

        return count;
    }
}; 
