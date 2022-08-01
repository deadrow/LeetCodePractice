class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] <= heights[i])
            {
                st.pop();
            }

            st.push(i);
        }

        vector<int>ret(st.size());
        int index = ret.size()-1;
        
        while(!st.empty())
        {
            ret[index--] = st.top();
            st.pop();
        }
        
        // reverse(ret.begin(), ret.end());
        return ret;
    }
};