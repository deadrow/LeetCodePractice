class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> adjList;
        for(auto it : paths)
            adjList[it[0]] = it[1];

        string start = paths[0][0];
        string dest;
        while(adjList.count(start))
        {
            dest = adjList[start];
            adjList.erase(start);
            start = dest;
        }

        return dest;
    }
};