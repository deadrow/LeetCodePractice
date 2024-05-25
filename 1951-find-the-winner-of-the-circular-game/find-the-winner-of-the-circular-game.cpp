class Solution {
public:
    int findTheWinner(int n, int k) {
        // Josephus problem
        queue<int>q;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()!=1) {
            int j=1;
            while(j<k) {
                int cur = q.front();
                q.pop();
                q.push(cur);
                j++;
            }
            q.pop();
        }
        return q.front();
    }
};