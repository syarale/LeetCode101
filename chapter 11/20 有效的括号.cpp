
// 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        // assert(!s.empty());
        
        int len = s.size();
        stack<char> stk;
        for (int i = 0; i < len; i++){
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                stk.push(s[i]);
                continue;
            }
            
            if (stk.empty()) {
                return false;
            }
            
            char ch = stk.top();
            if ((ch == '{' && s[i] == '}') || (ch == '(' && s[i] == ')') || 
                (ch == '[' && s[i] == ']')) {
                
                stk.pop();
            } else {
                return false;
            }
        }
        
        if (stk.empty()) {
            return true;
        } else {
            return false;
        }
    }
}; 
