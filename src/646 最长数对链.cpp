
// 646. Maximum Length of Pair Chain

class Solution {
public:
    bool cmp(vector<int> p1, vector<int> p2) {
        return p1[1] < p2[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        
        if (pairs.empty()) {
            return 0;
        }
        
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(len, 0);
        dp[0] = 1;
        int maxLen = dp[0];
        
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;

    }
}; 
