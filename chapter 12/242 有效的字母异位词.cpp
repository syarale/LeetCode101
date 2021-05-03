
// 242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.size();
        int tlen = t.size();

        if (slen != tlen) {
            return false;
        }

        vector<int> sdic(26, 0);
        vector<int> tdic(26, 0);

        for (int i = 0; i < slen; i++) {
            //assert(slen == tlen);
            sdic[s[i] - 'a'] ++;
            tdic[t[i] - 'a'] ++;
        }

        for (int i = 0; i < 26; i++) {
            if (sdic[i] != tdic[i]) {
                return false;
            }
        }

        return true;
    }
};
