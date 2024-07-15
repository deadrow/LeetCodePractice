class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int m=mat.size();
        int n = mat[0].size();
        int low = 0, high=n;
        while(low<high){
            int midCol = low +(high-low)/2;
            // Find out max in current column
            int maxRow=0;
            for(int i=0;i<m;i++){
                if(mat[i][midCol] > mat[maxRow][midCol]){
                    maxRow = i;
                }
            }

            int leftColVal = midCol == 0 ? -1 : mat[maxRow][midCol-1];
            int rightColVal = midCol == n-1 ? -1 : mat[maxRow][midCol+1];
            if(leftColVal < mat[maxRow][midCol] and mat[maxRow][midCol] > rightColVal)
                return {maxRow, midCol};
            else if(leftColVal > mat[maxRow][midCol])
                high = midCol;
            else low = midCol+1;
        }

        // find max row
        return{-1,-1};
    }
};