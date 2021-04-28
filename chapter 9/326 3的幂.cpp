
// 326. Power of Three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        
        int pos = n;
        while (pos > 1) {
            if (pos % 3 != 0) {
                return false;
            }
            
            pos /= 3;
        }
        
        return true;

    }
};
