
// 4. 寻找两个正序数组的中位数

class Solution {
public:
    
    // find the k-th element in nums1 and nums2
    int getKth(const vector<int>& nums1, const vector<int>& nums2, int k) {
        // assert(!nums1.empty() && !nums2.empty());
        // assert(0 < k && k < nums1.size() + nums2.size());
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        int begin1 = 0, end1 = len1 - 1;
        int begin2 = 0, end2 = len2 - 1;
        
        while (k >= 1) {
            int mid = k / 2;
            
            if (begin1 > end1) {
                return nums2[begin2 + k - 1];
            }  
            
            if (begin2 > end2) {
                return nums1[begin1 + k - 1];
            }
            
            if (k == 1) {
                return min(nums1[begin1], nums2[begin2]);
            }
            
            int loc1 = min(begin1 + mid - 1, end1);
            int loc2 = min(begin2 + mid - 1, end2);
            if (nums1[loc1] > nums2[loc2]) {
                k = k - (loc2 - begin2 + 1);   // update k first, and then update begin2 or beign1
                begin2 = loc2 + 1;
                
            } else {
                k = k - (loc1 - begin1 + 1);
                begin1 = loc1 + 1;
            }
        }
        
        // cann't happend
        return -1;
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // assert(!nums1.empty() && !nums2.empty());
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        int mid = (len1 + len2) / 2;
        
        if ((len1 + len2) % 2 == 0) {
            return double(getKth(nums1, nums2, mid) + getKth(nums1, nums2, mid + 1)) / 2; 
        } else {
            return double(getKth(nums1, nums2, mid + 1));
        }
    }
}; 
