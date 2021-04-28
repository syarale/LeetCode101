
// 504. Base 7

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        
        string str = "";
        int absNum = abs(num);
        
        int curr = absNum;
        while (curr != 0) {
            int add = curr % 7;
            str = to_string(add) + str;
            
            curr /= 7;
        }
        
        if (num < 0) {
            str = "-" + str;
        }
        
        return str;
    }
}; 
