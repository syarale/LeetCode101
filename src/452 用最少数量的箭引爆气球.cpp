// 452：用最少数量的箭引爆气球




/* 解法1 */ 
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    
    void copyCross(vector<int>& cross, vector<int> origin) {
        // assert: both the size of cross and origin are 2.
        
        cross[1] = origin[1];
        cross[0] = origin[0];
        return;
    }
    
    int getLength(vector<int>& cross) {
        // assert: cross's size is 2.
       return cross[1] - cross[0]; 
    }
    
    vector<int> computeCross(vector<int> point1, vector<int> point2) {
        // assert: both the size of point1 and point2 are 2.
        // assert: both the lengths of point1 and point2 aren't 0.
        
        vector<int> cross(2, 0);
        
        if (point1[0] > point2[1] || point2[0] > point1[1]) {
            return cross;
        }
        
        cross[1] = min(point1[1], point2[1]);
        cross[0] = max(point1[0], point2[0]);
        return cross;
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int num = 0;
        int len = points.size();
        vector<int> cross(2, 0);
        
        if (points.empty()) {
            return 0;
        }
        
        sort(points.begin(), points.end(), cmp);
        
        int i = 0;
        while (i < len) {
            if (getLength(cross) == 0) {
                copyCross(cross, points[i]); 
            } else {
                cross = computeCross(cross, points[i]);
                if (getLength(cross) == 0) {
                    num ++; // burst previous balloons
                    copyCross(cross, points[i]);
                }
            }
            
            if (i == len - 1) {
                // burst the last group ballons
                num ++;
            }
            i++;
        }
        
        return num;
    }
}; 


/* 解法2(优化后解法) */

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int num = 0;
        int len = points.size();
        
        if (points.empty()) {
            return 0;
        }
        
        sort(points.begin(), points.end(), cmp);
        int i = 0;
        while (i < len) {
            int k = points[i][1];
            int ptr = i + 1;
            while (ptr < len) {
                if (k < points[ptr][0] || k > points[ptr][1]) {
                    break;
                }
                ptr ++;
            }
            
            num ++;  // burst ballons
            i = ptr;
        }
        
        return num;
    }
}; 



 

