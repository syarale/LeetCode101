
// 461. Hamming Distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int count = 0;
        while (diff != 0) {
            count++;
            diff &= (diff - 1);
        }
        return count;
    }
}; 
