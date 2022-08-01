class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>ret;
        
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] <= heights[i])
            {
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};