class Solution {
public:
    vector<double>result;
    double dfs(map<string, vector<pair<string, double>>>& adjMap, string src, string dst, unordered_set<string>& visited, double curVal, int i)
    {
        if(src == dst)
        {
            result[i] = curVal;
            return true;
        }

        visited.insert(src);

        double ret = 1.0;
        for(auto [v, val] : adjMap[src])
        {
            if(visited.count(v) == 0)
            {
                if(dfs(adjMap, v, dst, visited, curVal*val, i))
                    return true;
            }
        }

        visited.erase(src);
        return false;
    }

    vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<string, vector<pair<string, double>>>adjMap;

        for(int i=0;i<equations.size();i++)
        {
            adjMap[equations[i][0]].push_back({equations[i][1], values[i]});
            adjMap[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        result.resize(queries.size());

        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string>visited;
            bool notPresent = (adjMap.count(queries[i][0]) == 0 || adjMap.count(queries[i][1]) == 0);
            if(notPresent || !dfs(adjMap, queries[i][0], queries[i][1], visited, 1.0, i))
                result[i] = -1.0;
        }

        return result;
    }

    // Floyd warshall approach
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<string, map<string, double>>adjMap;

        for(int i=0;i<equations.size();i++)
        {
            string from = equations[i][0];
            string to = equations[i][1];
            adjMap[from][to] = values[i];
            adjMap[to][from] = 1.0/values[i];
            adjMap[to][to] = adjMap[from][from]= 1.0;
        }

        result.resize(queries.size());

        // floyed warshall
        for(auto k : adjMap)
        {
            for(auto i : adjMap[k.first])
            {
                for(auto j : adjMap[k.first])
                {
                    adjMap[i.first][j.first] = adjMap[i.first][k.first]* adjMap[k.first][j.first];
                }
            }
        }

        for(int i=0;i<queries.size();i++)
        {
            string from = queries[i][0];
            string to = queries[i][1];
            if(adjMap.find(from) != adjMap.end() && adjMap[from].find(to) != adjMap[from].end())
                result[i] = adjMap[from][to];
            else
                result[i] = -1.0;
        }

        return result;
    }
};