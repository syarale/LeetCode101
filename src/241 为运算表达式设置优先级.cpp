
// 241. Different Ways to Add Parentheses 

// Use DP 

class Solution {
public:
    int compute(int x, int y, char opt) {
        switch (opt) {
            case '*' :
                return x * y;
                break;
            case '+':
                return x + y;
                break;
            case '-' :
                return x - y;
                break;
            default:
                // throw error
                return INT_MIN;
        }
    }
    
    vector<int> computeDp(int x, int y, vector<vector<int> > dpVal, char opt) {
        
        int lenx = dpVal[x].size();
        int leny = dpVal[y].size();
        vector<int> resVec;

        // assert(0 <= x && x <= lenx);
        // assert(0 <= y && y <= leny);
        for (int i = 0; i < lenx; i++) {
            for (int j = 0; j < leny; j++) {
                
                int tmp = compute(dpVal[x][i], dpVal[y][j], opt);
                resVec.push_back(tmp);
            }
        }

        return resVec;    
    }
    
    vector<int> diffWaysToCompute(string expression) {
        // assert expression is valid...
        
        int len = expression.size();
        vector<int> ret;
        
        if (expression.empty()) {
            return ret;
        }
        
        vector<int> number;
        vector<char> opt;
        
        int k = 0;
        while (k < len) {
            string tmp = "";
            int j = k;
            while (j < len && '0' <= expression[j] && expression[j] <= '9') {
                tmp += expression[j];
                j++;
            }
            
            number.push_back(stoi(tmp));
            if (j < len) {
                opt.push_back(expression[j]);
            }
            
            k = j + 1;
        }
        
        int numLen = number.size();
        int optLen = opt.size();
        vector<vector<int> > dp(numLen, vector<int>(numLen, -1));
        vector<vector<int> > dpVal;
        
        for (int i = 0; i < numLen; i++) {
            vector<int> tmp {number[i]};
            dpVal.push_back(tmp);
            dp[i][i] = dpVal.size() - 1;
        }
        
        for (int l = 1; l < numLen; l++) {
            for (int i = 0; i < numLen - l; i++) {
                vector<int> resVec;
                
                for (int j = i; j < i + l; j++) {
                    vector<int> tmp = computeDp(dp[i][j], dp[j + 1][i + l], dpVal, opt[j]);
                    resVec.insert(resVec.end(), tmp.begin(), tmp.end());
                }
                
                dpVal.push_back(resVec);
                dp[i][i + l] = dpVal.size() - 1;
            }
        }
        
        int loc = dp[0][numLen - 1];
        return dpVal[loc];

    }
};
