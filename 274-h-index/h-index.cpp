class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        // 6 5 3 1 0
        // 1 2 3 4 5
        for(int i=n-1;i>=0;i--){
            if(citations[i] >= i+1) return i+1;
        }

        return 0;
    }
};