class Trie {
public:
    struct Node {
        bool word;
        Node* children[26];
    };

    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(auto it : word){
            int c = it - 'a';
            if(!cur->children[c])
                cur->children[c] = new Node();
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(auto it : word){
            int c = it - 'a';
            if(!cur->children[c])
                return false;
            cur = cur->children[c];
        }
        return cur->word;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto it : prefix){
            int c = it - 'a';
            if(!cur->children[c])
                return false;
            cur = cur->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */