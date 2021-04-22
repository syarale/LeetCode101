
// 303. Range Sum Query - Immutable

class NumArray {
public:
    vector<int> sum;
    
    NumArray(vector<int>& nums) {
        int len = nums.size();
        sum.resize(len + 1, 0);
        for (int i = 0; i < len; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];

    }
};
