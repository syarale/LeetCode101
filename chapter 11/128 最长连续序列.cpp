// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int numLen = nums.size();
        int maxLen = 0;
        unordered_set<int> hash;
        
        if (numLen <= 1) {
            return numLen;
        }
        
        for (int i = 0; i < numLen; i++) {
            hash.insert(nums[i]);

        }
        
        while (!hash.empty()) {
            unordered_set<int>::iterator it = hash.begin();
            int curr = *it;
            int len = 0;
            
            while (it != hash.end()) {
                len++;
                int val = *it;
                hash.erase(val);
                it = hash.find(val + 1);
            }

            it = hash.find(curr - 1);
            while (it != hash.end()) {
                len++;
                int val = *it;
                hash.erase(val);
                it = hash.find(val - 1);
            }
             
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
}; 
