class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>st;
        
        st.insert(1);
        
        while(--n)
        {
            auto first = st.begin();
            long top = *first;
            st.erase(first);
            
            st.insert(top*2);
            st.insert(top*3);
            st.insert(top*5);
            
        }
        
        return *st.begin();
    }
};