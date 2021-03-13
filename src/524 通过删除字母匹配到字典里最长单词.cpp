// 524. 通过删除字母匹配到字典里最长单词


class Solution {
public:
    
    // if s 'include' t, return true; if not return false;
    // 'include' means that t can be formed by deleting some characters of s.
    bool isInclude(string s, string t) {
        // assert(!s.empty() && !t.empty());
        int sLen = s.size();
        int tLen = t.size();
        
        int i = 0, j = 0;
        while (j < tLen) {
            
            while (i < sLen && s[i] != t[j]) {
                i++;
            }
            
            if (i == sLen) {
                return false;
            }
            
            j++;
            i++;
        } 
        
        
        
        return true;
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        if (s.empty() || dictionary.empty()) {
            return "";
        }
        
        string maxStr = "";
        for (int i = 0; i < dictionary.size(); i++) {
            string t = dictionary[i];
            if (isInclude(s, t)) {
                if (t.size() > maxStr.size() || (t.size() == maxStr.size() && t < maxStr)) {
                    maxStr = t;
                }
            }
        }
        
        return maxStr;
    }
};
