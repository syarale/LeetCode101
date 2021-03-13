// 633.平方数之和

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = sqrt(c);
        
        while (i <= j) {
            int total = i * i + j * j;
            
            if (total == c) {
                return true;
            }
            
            if (total > c) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
}; 
