
// 215. 数组中的第k个最大元素

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        // assert(!nums.empty());
        // assert(0 <= i && i <= len - 1);
        // assert(0 <= j && j <= len - 1);
        
        int tmp = nums[i];
        
        nums[i] = nums[j];
        nums[j] = tmp;
        
        return;
    }
    
    int partition(vector<int>& nums, int l, int r) {
        // assert(!nums.empty());
        // assert(l <= r);
        
        if (l == r) {
            return l;
        }
        
        int i = l - 1;
        int pivot = nums[r];
        for (int j = l; j <= r - 1; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums, i, j);
            }
        }
        
        swap(nums, i + 1, r);
        return i + 1;
    }
    
    
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        // assert(!nums.empty() && 1 <= k && k <= len);
        // assert(l <= k && k <= r);
        
        int len = nums.size();
        int pth = partition(nums, l, r);   // the pivot position
        
        if (len - k == pth) {
            return nums[pth];
        }
        
        if (len - k < pth) {
            return quickSelect(nums, l, pth - 1, k);
        } else {
            return quickSelect(nums, pth + 1, r, k);
        }
        
    } 
    
    int findKthLargest(vector<int>& nums, int k) {
        // assert(!nums.empty() && 1 <= k && k <= len);
        int kth = 0;
        int l = 0, r = nums.size() - 1;
        
        kth = quickSelect(nums, l, r, k);
        return kth;
    }
}; 
