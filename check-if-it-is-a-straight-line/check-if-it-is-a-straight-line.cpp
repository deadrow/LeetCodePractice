class Solution {
public:
    float slope(const vector<int>& a, const vector<int>& b)
    {
        return float(b[1]-a[1])/(b[0]-a[0]);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float curSlope = slope(coordinates[0], coordinates[1]);

        for(int i=0;i<coordinates.size();i++)
        {
            for(int j=i+1;j<coordinates.size();j++)
            {
                if(abs(slope(coordinates[i], coordinates[j])) != abs(curSlope))
                    return false;
            }
        }

        return true;
    }
};