class MyCalendar {
public:
    map<int,int> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bookings[start]++;
        bookings[end]--;

        int prefixSum = 0;
        for(auto it : bookings)
        {
            prefixSum += it.second;
            if(prefixSum > 1)
            {
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */