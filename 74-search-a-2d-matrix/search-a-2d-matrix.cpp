class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n= matrix[0].size();
        int low=0, high=m*n;
        while(low<high){
            int mid = low + (high-low)/2;
            int midElem = matrix[mid/n][mid%n];
            if(target == midElem) return true;
            else if(target > midElem)
                low = mid+1;
            else high = mid;
        }
        return false;
    }
};