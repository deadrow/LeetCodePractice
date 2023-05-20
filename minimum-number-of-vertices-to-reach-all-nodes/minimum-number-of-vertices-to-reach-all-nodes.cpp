class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>inDegree(n);
        for(auto it : edges)
        {
            inDegree[it[1]]++;
        }

        vector<int>ret;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i] == 0)
                ret.push_back(i);
        }

        return ret;
    }
};