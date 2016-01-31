#include <map>
#include <iostream>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        label = false;
        memset(nodes, 0, sizeof nodes);
    }

    bool label;
    //map<char, TrieNode*> nodes;
    TrieNode* nodes[26];
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
                TrieNode* tmp = new TrieNode();
                dummy->nodes[c-'a'] = tmp;
            }
            dummy = dummy->nodes[c-'a'];
        }
        dummy->label=true;
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
        
        return dummy->label == true;
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
    
    bool searchWild(string wild) {
        return searchWild_(wild, 0, this->root);
    }
    
    bool searchWild_(string wild, int cur, TrieNode* root)
    {
        if (cur == wild.size())
            return root->label;

        char c = wild[cur];
        
        if (c != '.' )
        {
            return  root->nodes[c-'a'] && searchWild_(wild, cur+1, root->nodes[c-'a']);
        }
        else
        {
            for (int i=0; i<26; ++i)
            {
                if (root->nodes[i] && searchWild_(wild, cur+1, root->nodes[i]))
                    return true;
            }
            return false;
        }
    }
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class WordDictionary {
public:
    Trie trie;

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.searchWild(word);
        int pos = 0;
        int ret = true;
        for (;pos<word.size(); ++pos)
        {
            if (word[pos] == '.')
            {
                if (!trie.startsWith(word.substr(0, pos)))
                return false;
                
                for (int i=0; i<26; i++)
                {
                    string tmp(word);
                    tmp[pos] = 'a' + i;
                    if (trie.startsWith(tmp.substr(0, pos+1)))
                    {
                        bool ret = search(tmp);
                        
                        if (ret)
                            return true;
                    }
                }
                return false;
            }
        }
        return trie.search(word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main()
{
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.addWord("an");
    wd.addWord("add");
    //cout << wd.search("a") << endl;
    //cout << wd.search(".at") << endl;
    return 0;
//addWord("at"),addWord("and"),addWord("an"),addWord("add"),search("a"),search(".at"),addWord("bat"),search(".at"),search("an."),search("a.d."),search("b."),search("a.d"),search(".")
}
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
