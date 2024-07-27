class Solution {
public:
    unordered_map<string, vector<string>>adjMap;
    unordered_set<string>visited;

    void dfs(const string& email, vector<string>& mergedData){
        if(visited.count(email)) return;
        visited.insert(email);
        mergedData.push_back(email);
        for(auto& v : adjMap[email]){
            dfs(v, mergedData);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for(auto& data : accounts){
            string firstEmail = data[1];
            for(int i=2;i<data.size();i++){
                adjMap[firstEmail].push_back(data[i]);
                adjMap[data[i]].push_back(firstEmail);
            }
        }

        
        vector<vector<string>> ret;
        for(auto& data : accounts){
            vector<string>mergedData;
            mergedData.push_back(data[0]);
            if(!visited.count(data[1]))
                dfs(data[1], mergedData);
            sort(mergedData.begin()+1, mergedData.end());
            if(mergedData.size()>1)
                ret.push_back(mergedData);
        }
        return ret;
    }
};