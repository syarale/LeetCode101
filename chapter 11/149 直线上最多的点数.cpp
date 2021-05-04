
// 149. Max Points on a Line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        int maxNum = 0;
        map<pair<int, int>, int> hash;
        
        if (points.empty() || len <= 2) {
            return len;
        }
        
        for (int i = 0; i < len; i++) {
            hash.clear();
            
            for (int j = i + 1; j < len; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int g = gcd(dx, dy);
                
                if (hash.find({dx/g, dy/g}) != hash.end()) {
                    hash[{dx/g, dy/g}] ++;
                    maxNum = max(maxNum, hash[{dx/g, dy/g}]);
                    continue;
                } 

                if (hash.find({-dx/g, -dy/g}) != hash.end()) {
                    hash[{-dx/g, -dy/g}] ++;
                    maxNum = max(maxNum, hash[{-dx/g, -dy/g}]);
                    continue;
                }

                hash[{dx/g, dy/g}] = 2;
                maxNum = max(maxNum, hash[{dx/g, dy/g}]);
                
            } 
        }
        
        return maxNum;
    }
};
