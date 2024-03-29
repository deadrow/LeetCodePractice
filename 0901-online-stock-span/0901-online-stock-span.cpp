class StockSpanner {
public:
    stack<pair<int,int>>data;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int days = 1;
        while(!data.empty() && data.top().first <= price)
        {
            days += data.top().second;
            data.pop();
        }
        
        data.push({price, days});
        
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */