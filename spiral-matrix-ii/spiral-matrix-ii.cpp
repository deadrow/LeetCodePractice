class Solution {
public:
    vector<vector<int>> generateMatrix1(int n) {
        vector<vector<int>>mat(n, vector<int>(n));

        int r1 = 0;
        int r2 = n-1;
        int c1 = 0;
        int c2 = n-1;
        int counter = 1;
        while(r1 <= r2 && c1 <= c2)
        {
            for(int i=c1;i<=c2;i++)
                mat[r1][i] = counter++;

            for(int i=r1+1;i<=r2;i++)
                mat[i][c2] = counter++;

            for(int i=c2-1;i>=c1;i--)
                mat[r2][i] = counter++;
            
            for(int i=r2-1;i>r1;i--)
                mat[i][c1] = counter++;

            r1++;
            c1++;
            r2--;
            c2--;
        }

        return mat;
    }

    // official solution
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>mat(n, vector<int>(n));

        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};

        int counter = 1;
        int row = 0;
        int col = 0;
        int d = 0;

        auto floorMod = [](int x, int y) {
            return ((x % y) + y) % y;
        };

        while(counter <= n*n)
        {
            mat[row][col] = counter++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);
            if(mat[r][c] != 0)
                d = (d+1) % 4;
            
            row += dir[d][0];
            col += dir[d][1];
        }

        return mat;
    }
};