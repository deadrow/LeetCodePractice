class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto& a, const auto& b){
            if(a[0] == b[0])
                return (a[1]-a[0]) > (b[1]-b[0]);
            return a[0] < b[0];
        });
        
        int end = intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=end){
                count++;
            } else end = intervals[i][1];
        }
        return n-count;
    }
};