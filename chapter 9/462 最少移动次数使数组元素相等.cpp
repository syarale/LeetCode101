
// 462. Minimum Moves to Equal Array Elements II

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) {
            return -1;   // throw error
        }
        
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int total = 0;
        int ptr1 = 0, ptr2 = len - 1;
        while (ptr1 < ptr2) {
            total += (nums[ptr2] - nums[ptr1]);
            ptr1 ++;
            ptr2 --;
        }
        
        return total;
    }
}; 
