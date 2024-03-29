class Solution {
public:
    // Chebyshev distance
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int steps = 0;
        for(int i=1;i<points.size();i++)
        {
            steps += max(abs(points[i][1]-points[i-1][1]), abs(points[i][0]-points[i-1][0]));
        }

        return steps;
    }
};