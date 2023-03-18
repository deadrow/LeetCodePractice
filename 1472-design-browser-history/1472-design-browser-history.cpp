class BrowserHistory {
public:
    vector<string>navHistory;
    int navHistoryIndex{-1};
    BrowserHistory(string homepage) {
        navHistory.push_back(homepage);
        navHistoryIndex++;
    }
    
    void visit(string url) {
        int curSize = navHistory.size();
        navHistoryIndex++;
        if(navHistoryIndex < curSize)
        {
            navHistory.erase(navHistory.begin()+navHistoryIndex, navHistory.end());
        }
        
        navHistory.push_back(url);
        navHistoryIndex = navHistory.size()-1;
    }
    
    string back(int steps) {
        if(navHistoryIndex-steps < 0)
        {
            navHistoryIndex = 0;
            return navHistory[navHistoryIndex];
        }
        
        navHistoryIndex -= steps;
        return navHistory[navHistoryIndex];
    }
    
    string forward(int steps) {
        if(navHistoryIndex+steps >= navHistory.size())
        {
            navHistoryIndex = navHistory.size()-1;
            return navHistory[navHistoryIndex];
        }
        
        navHistoryIndex += steps;
        return navHistory[navHistoryIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */