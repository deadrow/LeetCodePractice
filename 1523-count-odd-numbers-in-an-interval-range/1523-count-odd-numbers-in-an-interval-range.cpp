class Solution {
public:
    int countOdds(int low, int high) {
        // int count = 0;
        // if(low & 1)
        // {
        //     count++;
        //     low = low+1;
        // }
        
        return (high+1)/2-low/2;
    }
};