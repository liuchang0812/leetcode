class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        TrieNode('#');
    }
    
    TrieNode(char c)
    {
        label = c;
    }
    char label;
    map<char, TrieNode*> nodes;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* dummy = root;
        
        for (auto c:word)
        {
            if (dummy->nodes[c-'a'] == NULL)
            {
                TrieNode* tmp = new TrieNode(c);
                dummy->nodes[c-'a'] = tmp;
            }
            dummy = dummy->nodes[c-'a'];
        }
        dummy->label='/';
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* dummy = root;
        
        for (auto c:word)
        {
            if (dummy->nodes[c-'a'] == NULL)
                return false;
            else
                dummy = dummy->nodes[c-'a'];
        }
        
        return dummy->label == '/';
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* dummy = root;
        
        for (auto c:prefix)
        {
            if (dummy->nodes[c-'a'] == NULL)
                return false;
            else
                dummy = dummy->nodes[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
