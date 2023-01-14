class UnionFind
{
public:
    UnionFind(int size)
        : root(size)
    {
        for(int i=0;i<size;i++)
        {
            root[i] = i;
        }
    }
    
    int find(int x)
    {
        if(x == root[x])
        {
            return x;
        }
        
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rootX < rootY)
                root[rootY] = rootX;
            else
                root[rootX] = rootY;
        }
    }
    
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
    
private:
    vector<int> root;
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>chars(26);
        
        for(int i=0;i<26;i++)
            chars[i] = i;
        
        UnionFind uf(26);
        
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i] != s2[i])
                uf.unionSet(s1[i]-'a', s2[i]-'a');
        }
        
        for(int i=0;i<baseStr.size();i++)
        {
            baseStr[i] = uf.find(baseStr[i]-'a') + 'a';
        }
        
        return baseStr;
    }
};