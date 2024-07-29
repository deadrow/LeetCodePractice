class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>indeg;
        for(auto& it : edges){
            indeg[it[0]]++;
            indeg[it[1]]++;
        }

        for(auto it : indeg){
            if(it.second == indeg.size()-1) return it.first;
        }
        return -1;
    }
};