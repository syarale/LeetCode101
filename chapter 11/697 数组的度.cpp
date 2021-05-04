
// 697. Degree of an Array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, vector<int> > hash;
        
        if (len <= 1) {
            return len;
        }
        
        for (int i = 0; i < len; i++) {
            if (hash.find(nums[i]) == hash.end()) {
                vector<int> tmp(3, 0);
                tmp[0] = 1;
                tmp[1] = i;
                tmp[2] = i;
                
                hash[nums[i]] = tmp;
            } else {
                hash[nums[i]][0] ++;
                hash[nums[i]][2] = i;
            }
        }
        
        int maxd = 0;
        int shortestLen = 0;
        unordered_map<int, vector<int> >::iterator it;
        
        for (it = hash.begin(); it != hash.end(); it++) {
            bool isLessLen = (it->second)[0] == maxd && ((it->second)[2] - (it->second)[1] + 1 ) < shortestLen;
            if ((it->second)[0] > maxd || isLessLen)
            {
               maxd = (it->second)[0];
               shortestLen = (it->second)[2] - (it->second)[1] + 1;
            }

        }
        
        return shortestLen;
    }
}; 
