class Solution {
public:
    double slope(vector<int>& point1, vector<int>& point2)
    {
        return (double)(point2[1] - point1[1])/(double)(point2[0] - point1[0]);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size() == 1)
            return 1;
        
        unordered_map<double, int> slopeMap;
        
		int maxPoints = 0;
		
		for(int i=0;i<points.size();i++)
		{
			int curMax = 0;
			int verticalPoints = 0;
			for(int j=i+1;j<points.size();j++)
			{
				if(points[i][0] == points[j][0])
					verticalPoints++;
				else
				{
					double curSlope = slope(points[i], points[j]);
					slopeMap[curSlope]++;
				}
			}
			
			for(auto it : slopeMap)
            {
                curMax = max(curMax, it.second);
            }
			
            curMax = max(curMax+1, verticalPoints+1);
			maxPoints = max(maxPoints, curMax);
			slopeMap.clear();
		}
		
		return maxPoints;
    }
};