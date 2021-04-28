
// 384. Shuffle an Array

class Solution {
private:
    vector<int> origin;
    
public:
    Solution(vector<int>& nums) {
        origin.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;

    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len = origin.size();
        vector<int> shuffled(origin);
        
        for (int i = 0; i < len; i++) {
            int another = rand() % len;
            int tmp = shuffled[i];
            shuffled[i] = shuffled[another];
            shuffled[another] = tmp;
        } 
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */ 
