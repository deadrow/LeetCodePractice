class Solution {
public:
    struct pt
    {
        int x, y;
    };
    
    int ccw(pt& a , pt& b , pt& c)
    {
        // How to find orientation
        // https://www.geeksforgeeks.org/orientation-3-ordered-points/
        double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
        if (v < 0) return -1; // clockwise
        if (v > 0) return +1; // counter-clockwise
        return 0;
    }
    
    bool equals(pt& a , pt& b)
    {
        return (a.x == b.x && a.y == b.y);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // Mix of topcoder and Cp algorithm
        // https://www.topcoder.com/thrive/articles/convex-hull
        // https://cp-algorithms.com/geometry/convex-hull.html#implementation
        
        if(trees.size() <= 3)
            return trees;
        
        vector<pt> points;
        for(auto it : trees)
        {
            points.push_back({it[0], it[1]});
        }
        
        // Find the lowest rightmost point
        pt p0 = *min_element(points.begin(), points.end(), [](pt a, pt b) {
            return make_pair(a.y, a.x) < make_pair(b.y, b.x);
        });
        
        
        sort(points.begin(), points.end(), [&](pt& a, pt& b){
            int v = ccw(p0, a, b);
            if(v == 0)
            {
                return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y) < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
            }
            
            return v < 0;
        });
          
        
        int i = points.size()-1;
        while (i >= 0 && ccw(p0, points[i], points.back()) == 0) i--;
        reverse(points.begin()+i+1, points.end());
        
        stack<pt> hull;
        hull.push(points[0]);
        hull.push(points[1]);

        vector<vector<int>> ret;

        // remove all anticlockwise combination of 3 points
        for(int k=2;k<points.size();k++)
        {
            pt top = hull.top();
            hull.pop();
            while(hull.size() > 0 && ccw(hull.top(), top, points[k]) >= 1)
            {
                top = hull.top();
                hull.pop();
            }
            
            hull.push(top);
            hull.push(points[k]);
        }
        
        while(!hull.empty())
        {
            ret.push_back({hull.top().x, hull.top().y});
            hull.pop();
        }
            
        return ret;
    }
};