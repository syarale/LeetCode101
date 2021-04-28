
// 204. Count Primes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        } 
        
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
               for (int j = i; j * i < n; j++) {
                   prime[j * i] = false;
               }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (prime[i]) {
                count++;
            }
        }
        
        return count;
    }
}; 
