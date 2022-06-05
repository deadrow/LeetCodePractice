class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const auto& a, const auto& b){
            return sqrt(abs(a[0]*a[0]) + abs(a[1]*a[1])) < sqrt(abs(b[0]*b[0]) + abs(b[1]*b[1]));
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        
        // sort(points.begin(), points.end(), [](const auto& a, const auto& b){
        //     return sqrt(abs(a[0]*a[0]) + abs(a[1]*a[1])) < sqrt(abs(b[0]*b[0]) + abs(b[1]*b[1]));
        // });
        
        vector<vector<int>> ret;
        for(int i=0;i<points.size();i++)
        {
            pq.push(points[i]);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        
        return ret;
            
    }
};