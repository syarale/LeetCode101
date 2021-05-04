
// 139. Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {
            return false;
        }
        
        int sLen = s.size();
        vector<bool> dp(sLen, false);
        for (int i = 0; i < sLen; i++) {
            if (dp[i]) {
                continue;
            }
            
            for (int j = 0; j < wordDict.size(); j++) {
                string word = wordDict[j];
                int wordLen = word.size();
                
                if (i - wordLen + 1 >= 0 && s.substr(i - wordLen + 1, wordLen) == word) {
                    if (i - wordLen < 0) {
                        dp[i] = true;
                    } else {
                        dp[i] = dp[i - wordLen];
                    }

                    if (dp[i]) {
                        break;
                    }
                }
            }
        }
        
        return dp[sLen - 1];
    }
};
