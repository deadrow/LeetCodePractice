class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bs(n);
        return bs.count();
    }
};