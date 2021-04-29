
// 260. Single Number III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        int sign = 0;
        if (ans == INT_MIN) {
            sign = 1;
        } else {
            sign = (ans & -ans);
        }
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & sign) == 0) {
                x ^= nums[i];
            } else {
                y ^= nums[i];
            }
        }

        vector<int> ret;
        ret.push_back(x);
        ret.push_back(y);
        return ret;
    }
}; 
