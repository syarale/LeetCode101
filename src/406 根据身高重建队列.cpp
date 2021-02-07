// 406 根据身高重建队列


class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        
        return a[0] < b[0];
    }
    
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        vector<vector<int> > queue(len, vector<int> (2, -1));
        
        if (people.empty()) {
            return queue;
        }
        
        sort(people.begin(), people.end(), cmp);
        
        for (int i = 0; i < len; i++) {
            int j = 0;
            int k = people[i][1];
            while (k > 0) {
                if (queue[j][0] == -1 || queue[j][0] >= people[i][0]) {
                    k--;
                    j++;
                } else {
                    j++;
                }
            }
            
            while (queue[j][0] != -1) {
                j++;
            }
            
            // locate the people
            queue[j][0] = people[i][0];
            queue[j][1] = people[i][1];
        }
        
        return queue;

    }
}; 
