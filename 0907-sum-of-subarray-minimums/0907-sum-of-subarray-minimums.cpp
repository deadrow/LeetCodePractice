class Solution {
public:
    // n^2 TLE
    int sumSubarrayMins1(vector<int>& arr) {
        
        int MOD = 1000000007;
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            int curMin = arr[i];
            sum = (sum + curMin) % MOD;
            for(int j=i+1;j<arr.size();j++)
            {
                curMin = min(curMin, arr[j]);
                sum = (sum + curMin) % MOD;
            }
        }
        
        return sum;
    }
    
    // monotonic stack
    int sumSubarrayMins(vector<int>& arr) {
        
        int MOD = 1000000007;
        long sum = 0;
        
        stack<int> st;
        // Find minimum at both left and right
        // of the current element. This would be
        // included in the range of all the subsets
        for(int i=0;i<=arr.size();i++)
        {
            while(!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i]))
            {
                int mid = st.top();
                st.pop();
                
                int leftMin = st.empty() ? -1 : st.top();
                int rightMin = i;
                
                long count = (mid-leftMin) * (rightMin-mid) % MOD;
                sum = (sum + arr[mid] * count) % MOD;
            }
            
            st.push(i);
        }
        
        return sum;
    }
};