class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        
        for(auto it : piles)
            pq.push(it);
        
        while(k--)
        {
            int top = pq.top();
            pq.pop();
            
            top = ceil((float)top/2);
            pq.push(top);
        }
        
        int sum = 0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};