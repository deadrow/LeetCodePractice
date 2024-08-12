class Solution {
public:
    bool canShip(vector<int>& weights, int days, int weight){
        int totalDays=1;
        int curWeight=0;
        for(int i=0;i<weights.size();i++){
            curWeight += weights[i];
            if(curWeight>weight){
                curWeight=weights[i];
                totalDays++;
                if(totalDays > days) return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<high){
            int mid = low + (high-low)/2;
            if(canShip(weights, days, mid))
                high=mid;
            else
                low = mid+1;
        }
        return low;
    }
};