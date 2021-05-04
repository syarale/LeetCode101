
// 91. Decode Ways

class Solution {
public:
    int toInt(string str, int i, int j) {
        // assert ....
        int number = 0;
        for (int k = i; k <= j; k++) {
            number = number * 10 + (str[k] - '0');
        }
        
        return number;
    }
    
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        
        int len = s.size();   
        vector<int> dp(len, 0);

        if ('0' < s[0] && s[0] <= '9') {
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }

        if (dp[0] == 0 || len == 1) {
            return dp[0];
        }

        int first = toInt(s, 1, 1);

        if (dp[0] > 0 && 0 < first && first <= 9) {
            dp[1] = dp[0];
        }

        int second = toInt(s, 0, 1);
        if (10 <= second && second <= 26) {
            dp[1] += 1;
        }

        for (int i = 2; i < len; i++) {
            int tmp = toInt(s, i, i);
            if (0 < tmp && tmp <= 9 ) {
                dp[i] += dp[i - 1];
            }
            
            tmp = toInt(s, i - 1, i);
            if (10 <= tmp && tmp <= 26) {
                dp[i] += dp[i - 2];
            }
        } 
        
        // for (int i = 1; i < len; i++) {
        //     cout<<dp[i]<<" ";
        // }

        return dp[len - 1];
        
    }
}; 
