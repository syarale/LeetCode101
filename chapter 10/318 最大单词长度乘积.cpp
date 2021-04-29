
// 318. Maximum Product of Word Lengths

class Solution {
public:
    int build(string str) {
        int res = 0;
        for (int i = 0; i < str.size(); i++) {
            int loc = str[i] - 'a';
            int tmp = 1;
            for (int j = 0; j < loc; j++) {
                tmp <<= 1;
            }
            
            res |= tmp;
        }

        return res;
    }

    int maxProduct(vector<string>& words) {
        map<string, int> hash;

        for (int i = 0; i < words.size(); i++) {
            hash[words[i]] = build(words[i]);
        }

        int maxVal = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((hash[words[i]] & hash[words[j]]) == 0) {
                    int len = words[i].size() * words[j].size();
                    maxVal = max(maxVal, len);
                }
            }
        }

        return maxVal;
    }
}; 
