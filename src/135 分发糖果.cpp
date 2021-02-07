// 135£º·Ö·¢ÌÇ¹û
#include <vector>
using namespace std; 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        
        if (ratings.empty()) {
            return 0;
        }
        
        vector<int> candies(len, 1); 
        for (int i = 1; i < len; i++) {
            if (ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
}; 
