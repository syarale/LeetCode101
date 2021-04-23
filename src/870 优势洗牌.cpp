
// 870. Advantage Shuffle 

class Solution {
public:
    struct cmp {
        bool operator ()(pair<int, int> node1, pair<int, int> node2) {
            return node1.first > node2.first;
        }
    };
    
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
       
        int len = A.size();
        vector<int> ret;
        queue<int> unmatch;
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> aheap, bheap;
        
        if (A.empty() || B.empty() || A.size() != B.size()) {
            return ret;
        }
        
        for (int i = 0; i < len; i++) {
            aheap.push({A[i], i});
            bheap.push({B[i], i});
        }
        
        ret.resize(len, -1);
        while (!aheap.empty() && !bheap.empty()) {
            pair<int, int> minb = bheap.top();
            bheap.pop();

            while (!aheap.empty() && (aheap.top()).first <= minb.first) {   // note: ' <= ', not ' < '
                pair<int, int> tmp = aheap.top();
                unmatch.push(tmp.first);
                aheap.pop();
            }
            
            if (!aheap.empty()) {
                pair<int, int> mina = aheap.top();
                aheap.pop();
                
                ret[minb.second] = mina.first;
                
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (ret[i] == -1) {
                // assert(!unmatch.empty()); 
                int tmp = unmatch.front();
                unmatch.pop();
                ret[i] = tmp;
            }
        }
        
        return ret;
    }
};
