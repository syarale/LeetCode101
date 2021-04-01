
// 347. 前K个高频元素

class Solution {
public:
    class cmp {
    public:
        bool operator() (const pair<int, int>& node1, const pair<int, int>& node2) {
            return node1.second > node2.second;
        }
        
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> topK(k, 0);
        unordered_map<int, int> buckets;
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> smallHeap;
        
        if (nums.empty()) {
            return topK;
        }
        
        for (int i = 0; i < len; i++) {
            buckets[nums[i]] ++;
        }
        
        unordered_map<int, int> ::iterator it = buckets.begin();
        for (int i = 0; i < k; i++) {
            if (it == buckets.end()) {
                break;
            }
            
            pair<int, int> tmp(it->first, it->second);
            smallHeap.push(tmp);
            it++;
        }
        
        while(it != buckets.end()) {
            if (it->second > (smallHeap.top()).second) {
                smallHeap.pop();
                smallHeap.push(pair<int, int> (it->first, it->second));
            }
            
            it++;
        }
        
        int pos = k - 1;
        while (!smallHeap.empty()) {
            pair<int, int> tmp = smallHeap.top();
            smallHeap.pop();
            topK[pos] = tmp.first;
            pos--;
            
//            topK.push_back(tmp.first);
        }
        
        return topK;
    }
}; 
