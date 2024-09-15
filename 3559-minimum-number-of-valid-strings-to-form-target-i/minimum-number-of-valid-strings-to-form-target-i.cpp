class Solution {
public:
    vector<int>memo;
    int MAX = 1e9;
    struct TrieNode{
        TrieNode* child[26];
    };

    TrieNode* root;
    void insert(string& word){
        TrieNode* cur = root;
        for(auto it : word){
            if(!cur->child[it-'a'])
                cur->child[it-'a'] = new TrieNode();
            cur = cur->child[it-'a'];
        }
    }
    int dp(vector<string>& words, string& target, int start){
        if(start>= target.size()) return 0;
        if(memo[start] != -1) return memo[start];
        int minCount = MAX;
        TrieNode* cur = root;
        // if target prefix from start is equal to word
        // or target prefix from start is equal to word substr
        for(int i=start;i<target.size();i++){
            // string targetPrefix = target.substr(start, i-start+1);
            // for(auto& word : words){
            //     if(word.substr(0, targetPrefix.size()) == targetPrefix){
            //         minCount = min(1+dp(words, target, i+1), minCount);
            //     }   
            // }
            if(!cur->child[target[i]-'a']) break;
            cur = cur->child[target[i]-'a'];
            minCount = min(1+dp(words, target, i+1), minCount);
        }
        return memo[start]=minCount;
    }
    int minValidStrings(vector<string>& words, string target) {
        root = new TrieNode();
        for(auto& it : words)
            insert(it);
        
        memo.resize(target.size(),-1);
        int ret = dp(words, target, 0);
        return ret != MAX ? ret : -1;
    }
};