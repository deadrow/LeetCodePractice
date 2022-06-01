class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        stack<vector<int>> st;
        st.push(intervals[0]);
        for(int j=1;j<intervals.size();j++)
        {
            if(intervals[j][0] <= st.top()[1])
            {
                vector<int> top = st.top();
                st.pop();
                st.push({top[0], max(intervals[j][1], top[1])});
            }
            else
                st.push(intervals[j]);
        }
        
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};