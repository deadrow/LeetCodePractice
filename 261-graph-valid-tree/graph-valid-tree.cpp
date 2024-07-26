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

    int roots(){
        int count=0;
        for(int i=0;i<root.size();i++)
            if(root[i] == i)
                count++;

        return count;
    }

private:
    vector<int>root;
    vector<int>rank;
};
class Solution {
public:
    bool cycle(vector<vector<int>>& adj, int src, int p, unordered_set<int>& visited){
        if(visited.count(src)) return true;
        visited.insert(src);
        for(auto v : adj[src]){
            if(v!=p and cycle(adj, v, src, visited)) return true;
        }
        return false;
    }
    bool validTree1(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_set<int> visited;
        return !cycle(adj, 0, -1, visited) and visited.size() == n;
    }

    // union find
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        bool cycle = false;
        for(auto it : edges){
            if(!uf.connected(it[0], it[1]))
                uf.unionSet(it[0], it[1]);
            else {
                cycle = true;
                break;
            }
        }

        return !cycle and uf.roots() == 1;
    }
};