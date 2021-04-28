
// 67. Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        } else if (b.empty()) {
            return a;
        }
        
        int aptr = a.size() - 1;
        int bptr = b.size() - 1;
        int add = 0;
        string sumStr = "";
        
        while (aptr >= 0 && bptr >= 0) {
            int sum = (a[aptr] - '0') + (b[bptr] - '0') + add;
            int curr = sum % 2;
            sumStr = char(curr + '0') + sumStr;
            
            add = sum / 2;
            aptr--;
            bptr--;
        }
        
        while (aptr >= 0 && add > 0) {
            int sum = (a[aptr] - '0') + add; 
            int curr = sum % 2;
            sumStr = char(curr + '0') + sumStr;
               
            add = sum / 2;
            aptr --;
        }
        
        if (aptr >= 0) {
            sumStr = a.substr(0, aptr + 1) + sumStr;
            aptr = -1;
        }

        
        while (bptr >= 0 && add > 0) {
            int sum = (b[bptr] - '0') + add; 
            int curr = sum % 2;
            sumStr = char(curr + '0') + sumStr;
               
            add = sum / 2;
            bptr --;
        } 
        
        if (bptr >= 0) {
            sumStr = b.substr(0, bptr + 1) + sumStr;
            bptr = -1;
        }
        
        if (add > 0) {
            sumStr = char(add + '0') + sumStr;
        }
        return sumStr;
    }
}; 
