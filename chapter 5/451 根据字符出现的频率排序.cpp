
// 451.根据字符出现的频率排序

class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        unordered_map<char, int> dic;
        
        if (s.empty()) {
            return "";
        } 
        
        int maxFreq = 0;
        for (int i = 0; i < len; i++) {
            dic[s[i]] ++;
            maxFreq = max(maxFreq, dic[s[i]]);
        }
        
        
        vector<vector<char> > buckets(maxFreq + 1);
        
        unordered_map<char, int>:: iterator it;
        for (it = dic.begin(); it != dic.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        
        string sortedStr = "";
        for (int i = buckets.size() - 1; i > 0; i--) {
            if (buckets[i].empty()) {
                continue;
            }
            
            for (int j = 0; j < buckets[i].size(); j ++) {
                for (int k = 0; k < dic[buckets[i][j]]; k++) {
                    sortedStr += buckets[i][j];
                }
            }
        }
        
        return sortedStr;
    }
}; 
