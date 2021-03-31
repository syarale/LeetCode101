// 69. x的平方根

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        
        if (x == 0) {
            return 0;
        }
        
        while (l <= r) {
            long mid = l + (r - l) / 2;
            long square = mid * mid;     // note: overflow if define mid and square as 'int' 
            if (square == x) {
                return mid;
            } else if (square > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return r;
    }
};
