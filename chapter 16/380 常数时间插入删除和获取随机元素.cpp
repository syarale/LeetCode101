
// 380. Insert Delete GetRandom O(1) 

class RandomizedSet {
private:
    vector<int> number;
    unordered_map<int, int> hash;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) == hash.end()) {
            number.push_back(val);
            hash[val] = number.size() - 1;
            return true;
        }

        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.find(val) != hash.end()) {
            int loc = hash[val];
            number[loc] = number[number.size() - 1];
            number.pop_back();

            hash[number[loc]] = loc;
            hash.erase(val);
            return true;
        }

        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % number.size();
        return number[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
