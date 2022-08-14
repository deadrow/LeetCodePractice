class Solution {
public:
    double angleClock(int hour, int minutes) {
        double val = 360.0 - abs(30*hour - 5.5*minutes);
        if(val > 180.0)
            return 360.0 - val;
        return val;
    }
};