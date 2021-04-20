
// 739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> days(len, 0);
        stack<int> temper;
        
        if (T.empty()) {
            return days;
        }
        
        temper.push(0);
        for (int i = 1; i < len; i++) {
            int val = T[i];
            while (!temper.empty() && T[temper.top()] < val) {
                days[temper.top()] = i - temper.top();
                temper.pop();
            }
            
            temper.push(i);
        }
        
        return days;
    }
};
