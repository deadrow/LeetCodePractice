class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret;
        
        // put 1st half
        int m = mat.size();
        int n = mat[0].size();
        
        bool flip = false;
        for(int i=0;i<m;i++)
        {
            int k = i;
            int j = 0;
            vector<int>temp;
            while(true)
            {
                if(k >= 0 && k < m && j >=0 && j < n)
                {
                    temp.push_back(mat[k][j]);
                    k--;
                    j++;
                }
                else
                    break;
            }
            
            if(flip)
            {
                for(auto it = temp.rbegin();it!=temp.rend();++it)
                    ret.push_back(*it);
            }
            else
            {
                for(auto it : temp)
                    ret.push_back(it);
            }
            
            flip = !flip;
        }
        
        // 2half
        for(int j=1;j<n;j++)
        {
            int i = m-1;
            int k = j;
            vector<int>temp;
            while(true)
            {
                if(i >= 0 && i < m && k >=0 && k < n)
                {
                    temp.push_back(mat[i][k]);
                    i--;
                    k++;
                }
                else
                    break;
            }
            
            if(flip)
            {
                for(auto it = temp.rbegin();it!=temp.rend();++it)
                    ret.push_back(*it);
            }
            else
            {
                for(auto it : temp)
                    ret.push_back(it);
            }
            
            flip = !flip;
        }
        
        return ret;
    }
};