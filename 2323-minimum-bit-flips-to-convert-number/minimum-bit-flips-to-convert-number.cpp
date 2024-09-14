class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xored = goal ^ start;
        int count = 0;
        // while (xored) {
        //     xored &= (xored - 1);
        //     count++;
        // }
        while (xored) {
            count += (xored & 1);
            xored >>= 1;
        }
        return count;
    }
};