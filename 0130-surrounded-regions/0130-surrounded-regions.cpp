class UnionFind
{
public:
    
    UnionFind(int size)
        : rank(size)
        , root(size)
    {
        for(int i=0;i<size;i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x)
    {
        if(x == root[x])
            return x;
        
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
                root[rootY] = root[rootX];
            else if(rank[rootY] > rank[rootX])
                root[rootX] = root[rootY];
            else
            {
                root[rootY] = root[rootX];
                rank[rootX] += 1;
            }
        }
    }
    
    bool isConnected(int x, int y)
    {
        return (find(x) == find(y));
    }
    
private:
    vector<int>root;
    vector<int>rank;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        UnionFind uf(m*n+1);
        
        int dummyNode = m*n;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O')
                {
                    if(i==0 || j==0 || i==m-1 || j==n-1)
                        uf.unionSet(dummyNode, i*n+j);
                    else
                    {
                        if(i>0 && board[i-1][j] == 'O')
                            uf.unionSet(i*n+j, (i-1)*n+j);
                        if(i < m && board[i+1][j] == 'O')
                            uf.unionSet(i*n+j, (i+1)*n+j);
                        if(j>0 && board[i][j-1] == 'O')
                            uf.unionSet(i*n+j, i*n+j-1);
                        if(j<n && board[i][j+1] == 'O')
                            uf.unionSet(i*n+j, i*n+j+1);
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(uf.isConnected(i*n+j, dummyNode))
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};