class MyCalendar {
public:
    set<vector<int>> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(intervals.empty())
        {
            intervals.insert({start, end});
            return true;
        }
        
        // less than all range
        vector<int> first = *intervals.begin();
        vector<int> last = *intervals.rbegin();
        if(end <= first[0] || start >= last[1])
        {
            intervals.insert({start, end});
            return true;
        }
        
        for(auto itr = intervals.begin();itr!= intervals.end();++itr)
        {
            if(start >= (*itr)[1] && end <= (*std::next(itr))[0])
            {
                intervals.insert({start, end});
                return true;
            }
        }
        
        // intervals.push_back({start, end});
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */