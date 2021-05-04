
// 313. Super Ugly Number

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // assert(!primes.empty());
        
        int uglyVal = 0;
        int len = primes.size();
        unordered_set<int> exist;
        priority_queue<int, vector<int>, greater<int> > heap;
        heap.push(1);
        exist.insert(1);
        
        for (int i = 1; i <= n; i++) {
            uglyVal = heap.top();
            heap.pop();
            
            if (i == n) {
                break;
            }
            
            for (int j = 0; j < len; j++) {
                int tmp = uglyVal * primes[j];
                if (exist.find(tmp) != exist.end()) {
                    heap.push(tmp);
                    exist.insert(tmp);
                } 
            } 
        }
        
        return uglyVal;
    }
}; 
