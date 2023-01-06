class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int minEnd = INT_MAX;
        int arrows = 0;
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0] > minEnd)
            {
                arrows++;
                minEnd = points[i][1];
            }
            else
                minEnd = min(minEnd, points[i][1]);
        }
        
        return arrows+1;
    }
};