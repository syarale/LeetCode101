
// 70. Climbing Stairs

class Solution {
public:
    int climbStairs(int n) {
        // assert(n >= 0);
        int ptr1 = 1;
        int ptr2 = 2;
        
        if (n <= 2) {
            return n;
        } 
        
        int num = 0;
        for (int i = 3; i <= n; i++) {
            int tmp = ptr1 + ptr2;
            ptr1 = ptr2;
            ptr2 = tmp;
        }
        
        num = ptr2;
        return num;
    }
}; 
