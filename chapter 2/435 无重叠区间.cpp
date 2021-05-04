// 435：无重叠区间 

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a.back() < b.back();
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int num = 0;
        int lastEnd = 0;
        int len = intervals.size();
 
        if (intervals.empty()) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        for (int i = 0; i < len; i++) {
            if (num == 0 || intervals[i][0] >= lastEnd) {
                num ++;
                lastEnd = intervals[i][1];
            }
        }
        
        return len - num;
    }
};
