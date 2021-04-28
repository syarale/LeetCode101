
// 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // assert nums is valid...
        
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return nums[len / 2]; 
    }
}; 
