class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int>indegree(numCourses);
        vector<vector<int>>adjMatrix(numCourses); 
        for(auto& it : prerequisites){
            indegree[it[0]]++;
            adjMatrix[it[1]].push_back(it[0]);
        }

        queue<int>bfs;
        vector<int>ret;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                bfs.push(i);
            }
        }
        
        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
            ret.push_back(cur);
            for(auto& v : adjMatrix[cur]){
                indegree[v]--;
                if(indegree[v] == 0)
                    bfs.push(v);
            }
        }
        return ret.size() == numCourses;
    }
};