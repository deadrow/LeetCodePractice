class Solution {
public:
    int getXDiff(vector<int>& a, vector<int>& b)
    {
        return a[0] - b[0];
    }
    int getYDiff(vector<int>& a, vector<int>& b)
    {
        return a[1] - b[1];
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaX = getXDiff(coordinates[1], coordinates[0]);
        int deltaY = getYDiff(coordinates[1], coordinates[0]);

        for(int i=2;i<coordinates.size();i++)
        {
            if(deltaX* getYDiff(coordinates[i], coordinates[0]) != deltaY* getXDiff(coordinates[i], coordinates[0]))
            return false;
        }

        return true;
    }
};