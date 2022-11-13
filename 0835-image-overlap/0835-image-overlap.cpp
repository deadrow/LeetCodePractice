class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // https://leetcode.com/problems/image-overlap/discuss/2747789/C%2B%2B-oror-Easy-Solution-oror-Beginner-Friendly
        
        vector<pair<int,int>>v1;
        vector<pair<int,int>>v2;
        
        int n = img1.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j])
                    v1.push_back({i,j});
                
                if(img2[i][j])
                    v2.push_back({i,j});   
            }
        }
        
        map<pair<int,int>, int> dict;
        int maxOverlap = 0;
        for(auto i : v1)
        {
            for(auto j : v2)
            {
                int x = i.first - j.first;
                int y = i.second - j.second;
                dict[{x,y}]++;
                maxOverlap = max(maxOverlap, dict[{x,y}]);
            }
        }
        
        return maxOverlap;
    }
};