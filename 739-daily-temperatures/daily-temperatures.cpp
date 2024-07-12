class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ret(temperatures.size());
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() and temperatures[st.top()] < temperatures[i]){
                ret[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }

        return ret;
    }
};