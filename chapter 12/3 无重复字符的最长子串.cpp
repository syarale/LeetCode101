
// 3. Longest Substring Without Repeating Characters 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_map<char, int> charPos;

        if (s.empty() || len == 1) {
            return len;
        }

        charPos[s[0]] = 0;
        int i = 0;
        int maxSub = 1;
        for (int j = 1; j < len; j++) {
            char ch = s[j];
            if (charPos.find(ch) != charPos.end()) {
                int loc = charPos[ch];

                for (int x = i; x <= loc; x++) {
                    charPos.erase(s[x]);
                }

                i = loc + 1;
            } 

            charPos[ch] = j;
            maxSub = max(maxSub, j - i + 1);
        }
        return maxSub;
    }
};
