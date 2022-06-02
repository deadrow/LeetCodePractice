class MedianFinder {
public:
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<>> right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left_max_heap.push(num);
        
        right_min_heap.push(left_max_heap.top());
        left_max_heap.pop();
        
        if(left_max_heap.size() < right_min_heap.size())
        {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {        
        if(left_max_heap.size() == right_min_heap.size())
            return double(left_max_heap.top() + right_min_heap.top())/2.0;
        else
            return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */