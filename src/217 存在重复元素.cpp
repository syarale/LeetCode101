
// 217. Contains Duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> hash;
        
        if (nums.empty()) {
            return false;
        }
        
        for (int i = 0; i < len; i++) {
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            }
            
            hash.insert(nums[i]);
        }
        
        return false;
        
    }
}; 
