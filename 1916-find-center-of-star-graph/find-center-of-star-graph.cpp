class Solution {
public:
    int findCenter1(vector<vector<int>>& edges) {
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
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstEdge = edges[0];
        vector<int> secondEdge = edges[1];

        return (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1])
                   ? firstEdge[0]
                   : firstEdge[1];
    }
};