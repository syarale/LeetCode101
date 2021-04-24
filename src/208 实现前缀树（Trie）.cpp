
// 208. Implement Trie (Prefix Tree)

struct Node {
    char ch;
    vector<Node* > children;
    bool isEnd;
    
    Node() {
        ch = '\0';
        isEnd = false;
        children.resize(26, NULL);
    }
    
    Node(char c) {
        ch = c;
        isEnd = false;
        children.resize(26, NULL);
    }
};


class Trie {
private:
    Node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
       root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        Node* ptr = root;
        
        for (int i = 0; i < len; i++) {
            int loc = word[i] - 'a';
            if ((ptr->children)[loc] == NULL) {
                Node* tmp = new Node(word[i]);
                (ptr->children)[loc] = tmp;
            }
            
            ptr = (ptr->children[loc]);
            if (i == len - 1) {
                ptr->isEnd = true;
            }
            
        }
        
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty()) {
            return false;
        }
        
        int loc = word[0] - 'a';
        int len = word.size();
        Node* ptr = (root->children)[loc];
        
        for (int i = 0; i < len; i++) {
            if (ptr == NULL || ptr->ch != word[i]) {
                return false;
            }
            
            if (i == len - 1) {
                if (ptr->isEnd) {
                    return true;
                } else {
                    return false;
                }
            }
            
            int nextLoc = word[i + 1] - 'a';
            ptr = (ptr->children)[nextLoc];
        }
        
        // not happen
        return false;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return false;
        }
        
        int loc = prefix[0] - 'a';
        int len = prefix.size();
        Node* ptr = (root->children)[loc];
        
        for (int i = 0; i < len; i++) {
            if (ptr == NULL || ptr->ch != prefix[i]) {
                return false;
            }
            
            if (i == len - 1) {
                return true;
            }
            
            int nextLoc = prefix[i + 1] - 'a';
            ptr = (ptr->children)[nextLoc];
        }
        
        // not happen
        return false;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */ 
