class MyCalendarThree {
public:
    map<int,int> bookings;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        bookings[startTime]++;
        bookings[endTime]--;

        int prefixSum = 0;
        int maxSum = 0;
        for(auto it : bookings)
        {
            prefixSum += it.second;
            maxSum = max(prefixSum, maxSum);
        }

        return maxSum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */