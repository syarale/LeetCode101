
// 409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();

        if (s.empty() || len == 1) {
            return len;
        }

        unordered_map<char, int> dic;
        for (int i = 0; i < len; i++) {
            dic[s[i]]++;
        }

        int palLen = 0, single = 0;
        unordered_map<char, int>::iterator it;
        for (it = dic.begin(); it != dic.end(); it++) {
            int num = it->second;
            if (num % 2 == 0) {
                palLen += num;
            } else {
                if (num > 1) {
                    palLen += (num - 1);
                } 

                single += 1;
            }
        }

        if (single > 0) {
            palLen += 1;
        }

        return palLen;
    }
};
