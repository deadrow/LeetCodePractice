class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nextGreater(n, -1);
        
        stack<int>st;
        
        // Because this is circular first time it will calculate
        // next greater element. Next time the entries would be
        // there in stack for those we couldn't find next grater
        // Second time they might find.
        for(int j=0;j<2;j++)
        {
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && nums[st.top()] < nums[i])
                {
                    nextGreater[st.top()] = nums[i];
                    st.pop();
                }

                st.push(i);
            }
        }

        return nextGreater;
    }
};