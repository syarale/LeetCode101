
// 693. Binary Number with Alternating Bits 

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n ^ (n>>1);
        return (tmp == INT_MAX || (tmp & (tmp+1)) == 0);
    }
};
