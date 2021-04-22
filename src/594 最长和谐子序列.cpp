
// 594. Longest Harmonious Subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> hash;  // hash is: val:count
        
        if (len <= 1) {
            return 0;
        }
        
        for (int i = 0; i < len; i++) {
            hash[nums[i]] ++;
        }
        
        int maxLen = 0;
        unordered_map<int, int>::iterator it;
        for (it = hash.begin(); it != hash.end(); it++) {
            int val = it->first;
            
            if (hash.find(val + 1) != hash.end()) {
                int num = hash[val] + hash[val + 1];
                maxLen = max(maxLen, num);
            }
        }
        
        return maxLen;
    }
}; 
