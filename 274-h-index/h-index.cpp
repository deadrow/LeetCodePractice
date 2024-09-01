class Solution {
public:
    int hIndex(vector<int>& citations) {
        // sort(citations.begin(), citations.end(), greater<int>());
        sort(citations.begin(), citations.end());
        int n = citations.size();
        // 6 5 3 1 0
        // 1 2 3 4 5
        // 0 1 3 5 6
        // 2 2 2 3 5
        // for(int i=n-1;i>=0;i--){
        //     if(citations[i] >= i+1) return i+1;
        // }
        int j=0;
        for(int i=0;i<n;i++){
            if(citations[i] >= n-i) j++;
        }

        return j;
    }
};