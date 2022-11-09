class StockSpanner {
public:
    vector<int>data;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int days = 0;
        data.push_back(price);
        
        for(int i=data.size()-1;i>=0;i--)
        {
            if(price >= data[i])
                days++;
            else
                break;
        }
        
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */