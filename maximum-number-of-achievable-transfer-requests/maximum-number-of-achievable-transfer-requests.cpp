class Solution {
public:
    int ans = 0;
    void helper(vector<vector<int>>& requests, vector<int>& indegree, int cur_i, int curCount)
    {
        if(cur_i == requests.size())
        {
            for (int i = 0; i < indegree.size(); i++)
            {
                if(indegree[i])
                    return;
            }

            ans = max(ans, curCount);
            return;
        }

        indegree[requests[cur_i][0]]--;
        indegree[requests[cur_i][1]]++;

        // take and leave
        helper(requests, indegree, cur_i+1, curCount+1);

        indegree[requests[cur_i][0]]++;
        indegree[requests[cur_i][1]]--;

        helper(requests, indegree, cur_i+1, curCount);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>indegree(n,0);

        helper(requests, indegree, 0, 0);
        return ans;
    }
};