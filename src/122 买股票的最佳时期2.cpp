// 122：买股票的最佳时期

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int> > res;
        
        if (prices.empty()) {
            return 0;
        } 
        
        int i = 0;
        while (i < len) {
            int j = i;
            while (j + 1 < len && prices[j] <= prices[j + 1]) {
                j ++;
            }
            
            if (j - i > 0) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                res.push_back(tmp);
            }
            
            i = j + 1;
        }
        
        
        int sum = 0;
        for (int i = 0; i < res.size(); i++) {
            sum += (res[i][1] - res[i][0]);
        } 
        
        return sum;
    }
}; 
