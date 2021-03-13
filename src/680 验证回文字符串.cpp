// 680. 验证回文字符串

class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        // assert(!s.empty() && 0 <= l && l <= r && r <= s.size() - 1);
        
        int i = l;
        int j = r;
        
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
    
    bool validPalindrome(string s) {
        int len = s.size();
        
        if (s.empty()) {
            return false;
        }
        
        int i = 0;
        int j = len - 1;
        
        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            }
        }
        
        return true;
    }
}; 
