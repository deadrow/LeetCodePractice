class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>visited;
        visited.insert({0,0});

        int x = 0, y = 0;
        for(auto it : path)
        {
            it == 'N' ? y++ : (it == 'S' ? y-- : y);
            it == 'E' ? x++ : (it == 'W' ? x-- : x);

            if(visited.count({x,y}))
                return true;

            visited.insert({x,y});
        }

        return false;

    }
};