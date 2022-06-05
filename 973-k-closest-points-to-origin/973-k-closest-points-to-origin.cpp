class Solution {
public:
    int distance(vector<int>& point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>> pq;

        vector<vector<int>> ret;
        for(int i=0;i<points.size();i++)
        {
            pair<int,int> curPoint = {distance(points[i]),i};
            if(pq.size() < k)
                pq.push(curPoint);
            else
            {
                if(curPoint.first < pq.top().first)
                {
                    pq.pop();
                    pq.push(curPoint);
                }
            }
        }
        
        while(!pq.empty())
        {
            ret.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ret;
            
    }
};