class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i=0, j=0;
        int end = -1;
        vector<int>cur;
        vector<int>ret;
        while(i<slots1.size() or j<slots2.size()){
            if(i >= slots1.size()){
                cur = slots2[j];
                j++;
            } else if(j >= slots2.size()){
                cur = slots1[i];
                i++;
            } else if(slots1[i][0] < slots2[j][0]){
                cur = slots1[i];
                i++;
            } else{
                cur = slots2[j];
                j++;
            }

            if(end != -1 and cur[0] < end) {
                ret = {cur[0], min(end, cur[1])};
                if(ret[1]-ret[0] >= duration)
                    return {ret[0], ret[0]+duration};
            }

            end = max(cur[1], end);
        }
        return {};
    }
};