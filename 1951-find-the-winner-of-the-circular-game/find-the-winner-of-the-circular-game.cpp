class Solution {
public:
    int findTheWinner1(int n, int k) {
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

    int find(int n, int k) {
        if(n == 1) return 0;
        return (find(n-1, k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        // through recursion
        return find(n,k)+1;
    }

};