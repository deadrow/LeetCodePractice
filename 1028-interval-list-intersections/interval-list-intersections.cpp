class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int i=0, j=0;
        int end = -1;
        vector<int>cur;
        while(i<firstList.size() or j<secondList.size()){
            if(i >= firstList.size()){
                cur = secondList[j];
                j++;
            } else if(j >= secondList.size()){
                cur = firstList[i];
                i++;
            } else if(firstList[i][0] < secondList[j][0]){
                cur = firstList[i];
                i++;
            } else{
                cur = secondList[j];
                j++;
            }

            if(end != -1 and cur[0] <= end) {
                ret.push_back({cur[0], min(end, cur[1])});
            }

            end = max(cur[1], end);
        }

        return ret;
    }
};