class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int,int>orderMap;
        for(int i=0;i<order.size();i++) orderMap[order[i]-'a']=i;

        for(int i=0;i<words.size()-1;i++){
            for(int j=0;j<words[i].size();j++){
                if(j >= words[i+1].size()) return false;
                if(words[i][j] != words[i+1][j]){
                    if(orderMap[words[i][j]-'a'] > orderMap[words[i+1][j]-'a']) return false;
                    else break; // order is fine
                }
            }
        }
        return true;
    }
};