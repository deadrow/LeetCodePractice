class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<>>pq;
        
        pq.push(1);
        
        while(--n)
        {
            long top = pq.top();
            
            while(!pq.empty() && top == pq.top())
                pq.pop();
            
            pq.push(top*2);
            pq.push(top*3);
            pq.push(top*5);
        }
        
        return pq.top();
    }
};