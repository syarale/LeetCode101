
// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxVal;
        deque<int> loc;
        
        if (nums.empty() || k <= 0) {
           return maxVal;    
        }
        
        for (int i = 0; i < k; i++) {
            if (i >= len) {
                break;
            }
            
            while (!loc.empty() && nums[loc.back()] < nums[i]) {
                loc.pop_back();
            }
            
            loc.push_back(i);
        }
        
        if (k >= len) {
            maxVal.push_back(nums[loc.front()]);
            return maxVal;
        }
        
        for (int i = k; i < len; i++) {
            if (loc.front() == i - k) {
                loc.pop_front();
            }
            
            while (!loc.empty() && nums[loc.back()] < nums[i]) {
                loc.pop_back();
            }
            loc.push_back(i);
            
            maxVal.push_back(nums[loc.front()]);
        }
        
        return maxVal;
    }
}; 
