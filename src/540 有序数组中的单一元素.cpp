// 540. 有序数组中的单一元素 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // assert(!nums.empty());
        
        int len = nums.size();
        int l = 0, r = len - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if ((nums[mid] != nums[mid - 1]) && nums[mid] != nums[mid + 1]) {
                return nums[mid];
                
            } else if (nums[mid] == nums[mid - 1]) {
                if ((mid - l + 1) % 2 != 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
                
                
            } else if (nums[mid] == nums[mid + 1]) {
                if ((r - mid + 1) % 2 != 0) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
                
            }
        }
        
        return nums[l];
    }
};
