/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int>indeg(n);
        vector<int>outdeg(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(knows(i, j)){
                    indeg[j]++;
                    outdeg[i]++;
                }
            }
        }

        int count=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(indeg[i] == n) {
                idx = i;
                count++;
                if(count >1 or outdeg[idx] > 1) return -1;
            }
        }
        return idx;
    }
};