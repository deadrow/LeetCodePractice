class Trie {
public:
    struct Node {
        bool word;
        Node* children[26];
        int childCount;
    };

    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(auto it : word){
            int c = it - 'a';
            if(!cur->children[c]){
                cur->children[c] = new Node();
                cur->childCount++;
            }
            
            cur = cur->children[c];
        }
        cur->word = true;
    }
        
    string findLongest(string word){
        if(root->childCount > 1) return "";

        Node* cur = root;
        string longest;
        for(auto it : word){
            int c = it - 'a';
            if(cur->children[c] and cur->childCount == 1 and !cur->word) {
                longest += it;
                cur = cur->children[c];
            }
        }
        return longest;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(auto it : strs)
            t.insert(it);

        return t.findLongest(strs[0]);
    }
};