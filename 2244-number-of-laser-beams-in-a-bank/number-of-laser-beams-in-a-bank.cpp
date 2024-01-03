class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int total = 0;
        for(auto& it : bank)
        {
            int ones = count(it.begin(), it.end(), '1');
            total += prev*ones;
            if(ones)
                prev = ones;
        }

        return total;
    }
};