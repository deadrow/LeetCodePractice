class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>ret(gain.size()+1);
        int maxAlt = 0;
        for(int i=0;i<gain.size();i++)
        {
            ret[i+1] = ret[i] + gain[i];
            cout << ret[i+1] << " ";
            maxAlt = max(maxAlt, ret[i+1]);
        }

        return maxAlt;
    }
};