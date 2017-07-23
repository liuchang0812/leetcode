

class Solution {
public:
  
    struct TrieNode {
    char c;
    bool term;
    TrieNode* children[26];
    TrieNode(char _c): c(_c), term(false) {
        memset(children, 0, sizeof children);
    }
	};

	void insertWord(TrieNode* root, const string& word, int pos=0) {

		//cout << "insert " <<  word << ' ' << pos << endl;

		if (pos == word.size())
		{
			//cout << "debug " << endl;
			if (root)
				root->term = true;
			//cout << "debug2 " << endl;
			return ;
		} else {
			char c = word[pos];
			
			if (root->children[c-'a'] == NULL)
			{
				root->children[c-'a'] = new TrieNode(c);
			}
			insertWord(root->children[c-'a'], word, pos+1);
			return;
		}
		return;
	}

	int queryWord(TrieNode* root, string word, int pos=0) {
		// 0: not exist
		//cout << "query " << word << ' ' << pos << endl;

		if (root->term)
			return pos;

		if (pos == word.size()) {
			return 0;
		} else {
			char c = word[pos];
			if (root->children[c-'a']) {
				return queryWord(root->children[c-'a'], word, pos+1);
			} else {
				return 0;
			}
		}
	}

    string replaceWords(vector<string>& dict, string sentence) {
          TrieNode* root;
        root = new TrieNode('#');

        for (const auto& i: dict) {
            insertWord(root, i);
        }
        vector<string> dict2;
        string tmp;
        for (auto i : sentence) {
            if (i == ' ') {
                dict2.push_back(tmp);
                tmp = ""; 
            }
            else  {
                tmp += i;
            }
        }
        if (tmp != "") dict2.push_back(tmp);

        for (int i=0; i<dict2.size(); i++) {
            int j = queryWord(root, dict2[i]);
            if (j)
                dict2[i] = dict2[i].substr(0, j);
        }
        string ret;
        for (int i=0; i<dict2.size(); i++) {
            ret += dict2[i] + " ";
        }
        cout << ret << endl;
        return ret.substr(0, ret.size()-1);
    }
};

