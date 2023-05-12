class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>dict;
        for(auto& it: logs)
        {
            dict[it[0]] += 1;
            dict[it[1]] += -1;
        }

        int maxOverLap = 0;
        int curOverLap = 0;
        int start = 0;
        for(auto& it : dict)
        {
            curOverLap += it.second;
            if(curOverLap > maxOverLap)
            {
                start = it.first;
                maxOverLap = curOverLap;
            }
        }

        return start;
    }
};