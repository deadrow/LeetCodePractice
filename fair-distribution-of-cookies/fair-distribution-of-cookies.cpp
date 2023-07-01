class Solution {
public:
    int backtrack(vector<int>& cookies, vector<int>& dist, int cur_i, int n)
    {
        if(cur_i >= n)
        {
            return *max_element(dist.begin(), dist.end());
        }

        int ret = INT_MAX;
        for(int i=0;i<dist.size();i++)
        {
            dist[i] += cookies[cur_i];
            ret = min(ret, backtrack(cookies, dist, cur_i+1, n));
            dist[i] -= cookies[cur_i];
        }

        return ret;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>dist(k);
        return backtrack(cookies, dist, 0, cookies.size());
    }
};