class StockPrice {
public:
    map<int,int>timestamps;
    priority_queue<pair<int,int>>maxHeap;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        timestamps[timestamp]=price;
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }
    
    int current() {
        return timestamps.rbegin()->second;
    }
    
    int maximum() {
        while(!maxHeap.empty() and timestamps[maxHeap.top().second] != maxHeap.top().first)
            maxHeap.pop();
        return maxHeap.top().first;
    }
    
    int minimum() {
        while(!minHeap.empty() and timestamps[minHeap.top().second] != minHeap.top().first)
            minHeap.pop();
        return minHeap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */