
// 528. Random Pick with Weight

class Solution {
private:
    vector<int> preSum; 
public:
    Solution(vector<int>& w) {
        preSum.assign(w.begin(), w.end());
        partial_sum(preSum.begin(), preSum.end(), preSum.begin());
    }
    
    int pickIndex() {
        int pos = rand() % preSum.back() + 1;
        return lower_bound(preSum.begin(), preSum.end(), pos) - preSum.begin();

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */ 
