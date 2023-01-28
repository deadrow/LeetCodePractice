class SummaryRanges {
public:
    set<int>track;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        track.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>> res;
        
        int prev = -1;
        
        for(auto it : track)
        {
            if(prev == -1)
            {
                res.push_back({it,it});
            }
            else if(it-1 == prev)
            {
                res.back()[1] = it;
            }
            else
                res.push_back({it,it});
            
            prev = it;
        }
        
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */