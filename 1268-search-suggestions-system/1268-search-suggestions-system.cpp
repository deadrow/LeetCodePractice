struct TrieNode
{
    bool word{false};
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c : word)
        {
            int idx = c - 'a';
            if(!cur->children[idx])
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        
        cur->word = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto c : word)
        {
            int idx = c - 'a';
            if(!cur->children[idx])
                return false;
            cur = cur->children[idx];
        }
        
        return cur->word;
    }
    
    void dfs(TrieNode* root, string curString)
    {
        if(!root || resultSet.size() == 3)
            return;
        
        if(root->word)
        {
            resultSet.push_back(curString);
        }
        
        for(char c='a'; c<='z';c++)
        {
            int idx = c - 'a';
            if(root->children[idx])
            {
                curString.push_back(c);
                dfs(root->children[idx], curString);
                curString.pop_back();
            }            
        }
    }
    
    vector<string> getChildrens(string prefix)
    {
        resultSet.clear();
        
        TrieNode* cur = root;
        for(auto c : prefix)
        {
            int idx = c - 'a';
            if(!cur->children[idx])
                return resultSet;
            cur = cur->children[idx];
        }
        
        string curString = prefix;
        dfs(cur, curString);
        
        return resultSet;
    }
    
private:
    TrieNode* root;
    vector<string>resultSet;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        
        Trie* trie = new Trie();
        for(auto it : products)
            trie->insert(it);
        
        string prefix;
        for(auto it : searchWord)
        {
            prefix += it;
            vector<string> childrens = trie->getChildrens(prefix);
            ret.push_back(childrens);
        }
        
        return ret;
    }
};