class UnionFind
{
public:
    UnionFind(int n)
        : parent(n)
        , rank(n)
        , size(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }
    }
    
    int find(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            else if(rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
            else
            {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                rank[rootX] += 1;
            }
        }
    }
    
    int getLargetSize()
    {
        int maxSize = 0;
        for(auto it : size)
        {
            maxSize = max(maxSize, it);
        }
        return maxSize;
    }
private:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dict;
        
        UnionFind uf(nums.size());

        for(int i=0;i<nums.size();i++)
        {
            if(dict.find(nums[i]) != dict.end())
                continue;
            
            if(dict.find(nums[i]-1) != dict.end())
                uf.unionSet(i, dict[nums[i]-1]);
            
            if(dict.find(nums[i]+1) != dict.end())
                uf.unionSet(i, dict[nums[i]+1]);
            
            dict[nums[i]] = i;
        }
            
        return uf.getLargetSize();
    }
};