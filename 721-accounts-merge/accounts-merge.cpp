class UnionFind{
public:
    UnionFind(int n) : root(n), rank(n){
        for(int i=0;i<n;i++){
            root[i]=i;
            rank[i]=1;
        }   
    }

    int find(int x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

    void unionSet(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] < rank[rooty]){
                root[rootx] = rooty;
            } else if(rank[rootx] > rank[rooty]) {
                root[rooty] = rootx;
            } else {
                root[rooty] = rootx;
                rank[rootx] += 1;
            }
        }
    }

private:
    vector<int>root;
    vector<int>rank;
};

class Solution {
public:
    unordered_map<string, vector<string>>adjMap;
    unordered_set<string>visited;

    void dfs(const string& email, vector<string>& mergedData){
        mergedData.push_back(email);
        for(auto& v : adjMap[email]){
            if(!visited.count(v)) {
                visited.insert(v);
                dfs(v, mergedData);
            }
        }
    }
    vector<vector<string>> accountsMerge1(vector<vector<string>>& accounts) {
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
            if(!visited.count(data[1])) {
                visited.insert(data[1]);
                dfs(data[1], mergedData);
            }

            if(mergedData.size()>1){
                sort(mergedData.begin()+1, mergedData.end());
                ret.push_back(mergedData);
            }
        }
        return ret;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(accounts.size());
        unordered_map<string, int>accountMap;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(!accountMap.count(accounts[i][j]))
                    accountMap[accounts[i][j]] = i;
                else
                    uf.unionSet(i, accountMap[accounts[i][j]]);
            }
        }
        unordered_map<int, vector<string>>accountGroups;
        for(auto& it : accountMap){
            int parent = uf.find(it.second);
            accountGroups[parent].push_back(it.first);
        }

        vector<vector<string>> ret;
        for(auto& it : accountGroups){
            vector<string>cur;
            cur.push_back(accounts[it.first][0]);
            sort(it.second.begin(), it.second.end());
            cur.insert(cur.end(), it.second.begin(), it.second.end());
            ret.push_back(cur);
        }
        return ret;
    }
};
