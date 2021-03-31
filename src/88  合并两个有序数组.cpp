// 88 合并两个有序数组

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // assert the input is valid
        int i = m - 1;
        int j = n - 1;
        int curr = nums1.size() - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[curr] = nums1[i];
                i--;
            } else {
                nums1[curr] = nums2[j];
                j--;
            }
            
            curr--;
        }
        
        if (j >= 0) {
            for (int k = 0; k <= j; k++) {
                nums1[k] = nums2[k]; 
            }
        }
        
        return;
    }
}; 
