class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> supply_dict(supplies.begin(), supplies.end());
        
        unordered_map<string, int> indegree;
        for(auto it : recipes)
            indegree[it] = 0;
        
        
        unordered_map<string, vector<string>> adjacency_map;
        
        for(int i=0;i<ingredients.size();i++)
        {
            for(auto ingred : ingredients[i])
            {
                if(supply_dict.find(ingred) == supply_dict.end())
                {
                    adjacency_map[ingred].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        
        
        vector<string> res;
        queue<string> bfs;
        for(auto it : indegree)
        {
            if(it.second == 0)
                bfs.push(it.first);
        }
        
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                string node = bfs.front();
                bfs.pop();
                res.push_back(node);
                
                for(auto it : adjacency_map[node])
                {
                    indegree[it]--;
                    if(indegree[it] == 0)
                        bfs.push(it);
                }
            }
        }
        
        return res;
    }
};