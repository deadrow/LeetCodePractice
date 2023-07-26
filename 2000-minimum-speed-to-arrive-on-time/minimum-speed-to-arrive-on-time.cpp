class Solution {
public:
    bool canReach(vector<int>& dist, int speed, double hour)
    {
        double cur = 0.0;
        int n = dist.size();
        for(int i=0;i<n;i++)
        {
            if(i == n-1)
                cur += (1.0*dist[i])/speed;
            else
                cur += ceil((1.0*dist[i])/speed);

            if(cur > hour)
                return false;
        }

        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7+1;

        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(canReach(dist, mid, hour))
                right = mid;
            else
                left = mid+1;
        }

        return left == 1e7+1 ? -1 : left;
    }
};