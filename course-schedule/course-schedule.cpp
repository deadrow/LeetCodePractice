class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);

        vector<vector<int>>adjList(numCourses);

        for(auto it : prerequisites)
        {
            indegree[it[0]]++;
            adjList[it[1]].push_back(it[0]);
        }

        int courseTaken = 0;
        queue<int>bfs;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                courseTaken++;
                bfs.push(i);
            }
        }
        
        while(!bfs.empty())
        {
            int u = bfs.front();
            bfs.pop();

            for(auto v : adjList[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    courseTaken++;
                    bfs.push(v);
                }
            }
        }

        return courseTaken==numCourses;
    }
};