class TrieNode{
    public:
    
    TrieNode* children[26];
    bool term;
    
    TrieNode()
    {
        term = false;
        
        for (size_t i=0; i<26; ++i)
            children[i] = NULL;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void Insert(const string& s)
    {
        TrieNode* cur = root;
        
        for (auto c:s)
        {
            TrieNode* tmp = cur->children[c-'a'];
            if (tmp == NULL)
            {
                TrieNode* newNode = new TrieNode();
                cur->children[c-'a'] = newNode;
                cur = newNode;
            }
            else
                cur = tmp;
        }
        cur->term = true;
    }
    
    bool Query(const string& s)
    {
        TrieNode* cur = root;
        
        for (auto c:s)
        {
            if (cur->children[c-'a'] == NULL)
                return false;
            else
            {
                cur = cur->children[c-'a'];
            }
        }
        return cur->term;
    }
    
    bool QueryPrefix(const string& s)
    {
        TrieNode* cur = root;
        
        for (auto c:s)
        {
            //cout << "query prefix " << c << endl;
            if (cur->children[c-'a'] == NULL)
                return false;
            else
            {
                cur = cur->children[c-'a'];
            }
        }
        return !cur->term;
    }
};



class Solution {
public:
    set<string> ans;
    map<pair<int,int>, bool> visited;
    void dfs(int x, int y, const vector<vector<char>>& board, TrieNode* trie, string cur)
    {
        if (trie == NULL)
       {
           return;
       }
       if (trie->term)
       {
           ans.insert(cur);
           //cout << "Get Ans " << cur << endl;
       }

       if (x < 0 || y < 0 || x == board.size() || y == board[0].size())
            return;
       
       static int dx[] = {0, 0, -1, 1};
       static int dy[] = {-1, 1, 0, 0};
       //cout << "dfs " << x << ' ' << y << ' ' << cur << endl;
       for (size_t i=0; i<4; ++i)
       {
           int px = x + dx[i];
           int py = y + dy[i];
           if (visited[make_pair(px, py)]) continue;
           visited[make_pair(px,py)] = true;
           //cout << x <<' ' << y << " to " << px << ' ' << py << endl;
           dfs(px, py, board, trie->children[board[x][y]-'a'], cur + board[x][y]);
           visited[make_pair(px,py)] = false;
       }
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto s:words)
            trie.Insert(s);
        for (size_t i=0; i<board.size(); ++i)
            for (size_t j=0; j<board[0].size(); ++j)
            {
                visited[make_pair(i,j)] = true;
                dfs(i,j, board, trie.root, "");
                visited[make_pair(i,j)] = false;
            }
        vector<string> res;
        
        for (auto s:ans)
            res.push_back(s);
        return res;
    }
};
