// 81.ËÑË÷Ğı×ªÅÅĞòÊı×é II

class Solution {
public:
    bool binarySearch(const vector<int>& nums, int begin, int end, int target) {
        // assert(...);
        
        int l = begin, r = end;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            } 
            
            if (target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            } 
        }
        
        return false;
    }
    
    
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        
        if (nums.empty()) {
            return false;
        }
        
        int l = 0, r = len - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    return binarySearch(nums, l, mid, target);
                } else {
                    l = mid + 1;
                }
                
            } else if (nums[mid] < nums[r]) {
                if (nums[mid] <= target && target <= nums[r]) {
                    return binarySearch(nums, mid, r, target);
                } else {
                    r = mid - 1;
                }
                
            } else if (nums[mid] == nums[l]) {
                l++;
                
            } else if (nums[mid] == nums[r]) {
                r--;
                
            }
        }
        
        return false;
        
    }
}; 
