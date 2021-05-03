
// 5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string retStr = "";
        if (s.empty()) {
            return retStr;
        }

        if (len == 1) {
            return (retStr + s[0]);
        }

        vector<vector<bool> > dp(len, vector<bool>(len, false));
        int maxLen = 1;
        pair<int, int> palStr(0, 0);

        for (int i = 0; i < len - 1; i++) {
            dp[i][i] = true;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLen = 2;
                palStr.first = i;
                palStr.second = i + 1;
            }
        }
        dp[len - 1][len - 1] = true;

        for (int l = 2; l < len; l++) {
            for (int i = 0; i < len - l; i++) {
                dp[i][i + l] = ((s[i] == s[i + l]) && dp[i + 1][i + l - 1]);
                if (dp[i][i + l] && l + 1 > maxLen) {
                    maxLen = l + 1;
                    palStr.first = i;
                    palStr.second = i + l;
                }
            }
        }

        return s.substr(palStr.first, maxLen);
    }
};
