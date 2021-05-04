// 154.寻找旋转排序数组中的最小值 II 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        
        // assert(!nums.empty());
        
        int l = 0, r = len - 1;
        if (nums[l] < nums[r]) {
            return nums[l];
        }
        
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            
            if (nums[l] < nums[r]) {
                return nums[l];
            }
            
            if (nums[mid] > nums[l]) {
                l = mid;
            } else if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] == nums[l] && nums[mid] != nums[r]) {
                l = mid;
            } else if (nums[mid] == nums[r] && nums[mid] != nums[l]) {
                r = mid;
            } else if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
                l++;
            }
        }
        
        return nums[r];
    }
};
