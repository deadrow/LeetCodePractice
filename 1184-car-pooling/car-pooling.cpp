class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>sweep;
        for(auto it : trips)
        {
            sweep[it[1]] += it[0];
            sweep[it[2]] -= it[0];
        }

        int curCapacity = 0;
        for(auto it : sweep)
        {
            curCapacity += it.second;
            if(curCapacity > capacity)
                return false;
        }

        return true;
    }
};