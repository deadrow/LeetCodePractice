class MyCalendar {
public:
    set<pair<int,int>> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto iter = intervals.upper_bound({start,end});
        
        if(iter != intervals.end() && iter->first < end)
            return false;
        
        if(iter != intervals.begin() && start < (--iter)->second)
            return false;
        
        intervals.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */