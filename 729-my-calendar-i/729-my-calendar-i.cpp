class MyCalendar {
public:
    set<pair<int,int>> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(intervals.empty())
        {
            intervals.insert({start, end});
            return true;
        }
        
        // less than all range
        auto first = *intervals.begin();
        auto last = *intervals.rbegin();
        if(end <= first.first || start >= last.second)
        {
            intervals.insert({start, end});
            return true;
        }
        
        for(auto itr = intervals.begin();itr!= intervals.end();++itr)
        {
            if(start >= (*itr).second && end <= (*std::next(itr)).first)
            {
                intervals.insert({start, end});
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */