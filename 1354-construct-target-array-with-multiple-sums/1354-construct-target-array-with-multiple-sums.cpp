class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if(n == 1)
            return target[0] == 1;
        
        priority_queue<int> pq;
        
        
        long totalSum = 0;
        for(auto it : target)
        {
            pq.push(it);
            totalSum += it;
        }
        
        while(!pq.empty())
        {
            auto largest = pq.top();
            pq.pop();
            
            int rest = totalSum - largest;
            
            if(rest == 1)
                return true;
            
            int x = largest % rest;
            
            if(x == 0 || x == largest)
                return false;

            pq.push(x);
            
            totalSum = totalSum - largest + x;
            if(totalSum == n)
                return true;
        }
        
        return true;
    }
};