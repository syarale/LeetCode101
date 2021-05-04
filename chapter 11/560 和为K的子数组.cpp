
// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> hash;
        
        
        if (nums.empty()) {
            return 0;
        }
        
        hash[0] = 1;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            count += hash[sum - k];
            hash[sum]++;
        }
        
        return count;

    }
};
