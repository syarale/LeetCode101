// 34. 在排序数组中查找元素的第一个和最后一个位置 

class Solution {
public:
    const int LOWER = 0;
    const int UPPER = 1;
    
    int binarySearch(vector<int>& nums, int target, int type) {
        // assert(!nums.empty());
        int len = nums.size();
        int l = 0, r = len - 1;
        
        if (target < nums[0]) {
            return -1;
        }
        
        if (target > nums[len - 1]) {
            return len;
        }
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (target == nums[mid]) {
                if (type == LOWER) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (target < nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        // assert(l == r);
        if (type == LOWER) {
            return l;
        } else {
            if (nums[l] > target) {
                return l;
            } else {
                return l + 1;
            } 
        }
        
    } 
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int leftIdx = 0;
        int rightIdx = 0;
        vector<int> res(2, -1);
        
        if (nums.empty()) {
            return res;
        }
        
        leftIdx = binarySearch(nums, target, LOWER);
        if (leftIdx == -1 || leftIdx == len) {
            return res;
        }
        
        rightIdx = binarySearch(nums, target, UPPER);
        if (leftIdx != rightIdx) {
            res[0] = leftIdx;
            res[1] = rightIdx - 1;
        }
             
        return res;
    }
};
