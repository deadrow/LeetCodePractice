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
            count += root[i]==i;
        return count;
    }

private:
    vector<int>root;
    vector<int>rank;
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto& it : edges)
            uf.unionSet(it[0], it[1]);

        return uf.roots();
    }
};