// 76. 最小覆盖子串 (滑动窗口) 

class Solution {
public:
    string minWindow(string s, string t) {
        
        int l = 0, r = 0;
        int distance = 0;
        int minSize  = s.size() + 1;
        int minBegin = -1;
        vector<int> sHash(128, 0);
        vector<int> tHash(128, 0);
        
        int tLen = t.size();
        
        if (s.empty() || t.empty()) {
            return "";
        }
        
        
        for (int i = 0; i < tLen; i++) {
            tHash[t[i]] ++;
        }
        
        
        while (r < s.size()) {
            while (r < s.size()) {
                
                if (sHash[s[r]] < tHash[s[r]]) {
                    distance ++;
                    // cout<<"distance ++ : " <<distance<<endl;
                }

                sHash[s[r]] ++;

                if (distance == tLen) {
                    break;
                } else {
                    r ++;
                }

            }
            
            if (r == s.size()) {
                break;
            }
            
            // cout<<"r: " <<r<<endl;
            // cout<<"dis: "<<distance<<endl;

            while (l <= r) {
                if (sHash[s[l]] == tHash[s[l]]) {
                    distance --;
                }
                
                sHash[s[l]] --;
                l ++;
                
                if (distance < tLen) {
                    if (r - l + 2 < minSize) {
                        minSize = r - l + 2;
                        minBegin = l - 1;
                    }
                    
                    break;
                }
                
            }
            
            if (l > r) {
                // it may not happen;
                break;
            }
            
            r ++;   
        }
        
        // cout<<l<< " "<< r<<endl;
        // cout<<"minSize: "<<minSize<<endl;
        // cout<<"minBegin: "<<minBegin<<endl;

        if (minBegin == -1) {
            return "";
        } else {
            return s.substr(minBegin, minSize);
        }

    }
};
