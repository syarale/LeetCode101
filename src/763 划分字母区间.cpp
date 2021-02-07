// 763：划分字母区间

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int> > label(26, vector<int>(2, -1));
        int len = S.size();
        vector<int> res;
        
        if (len < 2) {
            res.push_back(len);
            return res;
        } 
        
        for (int i = 0; i < len; i++) {
            int x = S[i] - 'a';
            if (label[x][0] == -1) {
                label[x][0] = i;
                label[x][1] = i;
            } else {
                label[x][1] = i;
            }
        }
        
        
        int loc = S[0] - 'a';
        int currStart = label[loc][0];
        int currEnd = label[loc][1];
        
        for (int i = 1; i < len; i++) {
            int x = S[i] - 'a';
            if (i > currEnd) {
                res.push_back(currEnd - currStart + 1);
                currStart = label[x][0];
                currEnd = label[x][1];
            } else {
                currEnd = max(currEnd, label[x][1]);
            }
            
            if (i == len - 1) {
                res.push_back(currEnd - currStart + 1);
            }
        }
        
        return res;
    }
}; 
