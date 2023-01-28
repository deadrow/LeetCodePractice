class SummaryRanges {
public:
    vector<vector<int>>intervals;
    set<int>track;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(track.find(value) == track.end())
        {
            track.insert(value);
            intervals.push_back({value,value});
        }
            
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);
        for(int j=1;j<intervals.size();j++)
        {
            if(intervals[j][0]-1 == res.back()[1])
            {
                res.back()[1] = max(intervals[j][1],res.back()[1]);
            }
            else
                res.push_back(intervals[j]);
        }
        
        return intervals = res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */