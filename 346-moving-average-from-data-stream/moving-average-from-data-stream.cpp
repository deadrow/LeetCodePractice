class MovingAverage {
public:
    deque<int>dq;
    int maxWindow;
    int movingSum=0;
    MovingAverage(int size) : maxWindow(size){
    }
    
    double next(int val) {
        movingSum += val;
        dq.push_back(val);
        if(dq.size() > maxWindow){
            int first = dq.front();
            dq.pop_front();
            movingSum -= first;
        }

        return (1.0*movingSum)/dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */