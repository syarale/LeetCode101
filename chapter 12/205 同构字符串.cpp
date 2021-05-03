
// 205. Isomorphic Strings 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.size();
        int tlen = t.size();

        if (slen != tlen) {
            return false;
        }

        unordered_set<char> hash;
        unordered_map<char, char> dic;
        for (int i = 0; i < slen; i++) {
            //assert(slen == tlen);

            if (dic.find(s[i]) == dic.end()) {
                if (hash.find(t[i]) != hash.end()) {
                    return false;
                } 

                dic[s[i]] = t[i];
                hash.insert(t[i]);
                continue;
            }

            // assert(dic.find(s[i]) != dic.end());
            if (dic[s[i]] != t[i]) {
                return false;
            }

        }

        return true;
    }
};
