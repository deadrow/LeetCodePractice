/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isSame(vector<vector<int>>& grid, int r, int c, int length)
    {
        for(int i=r;i<r+length;i++)
        {
            for(int j=c;j<c+length;j++)
            {
                if(grid[i][j] != grid[r][c])
                    return false;
            }
        }
        
        return true;
    }
    
    Node* constructUtil(vector<vector<int>>& grid, int r, int c, int length)
    {
        if(isSame(grid, r, c, length))
        {
            return new Node(grid[r][c], true);
        }
        
        Node* cur = new Node(false, false);
        cur->topLeft = constructUtil(grid, r, c, length/2);
        cur->topRight = constructUtil(grid, r, c+length/2, length/2);
        cur->bottomLeft = constructUtil(grid, r+length/2, c, length/2);
        cur->bottomRight = constructUtil(grid, r+length/2, c+length/2, length/2);
        
        return cur;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return constructUtil(grid, 0, 0, grid.size());
    }
};