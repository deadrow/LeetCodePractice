class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        for(auto it : tasks)
            freq[it]++;

        priority_queue<int>pq;
        for(auto it : freq)
            pq.push(it.second);

        deque<pair<int,int>>timeQueue;

        int time=0;
        while(!pq.empty() or !timeQueue.empty()){
            time += 1;
            if(!pq.empty()){
                int count = pq.top()-1;
                pq.pop();
                if(count)
                    timeQueue.push_back({count, time+n});
            }

            if(!timeQueue.empty() and timeQueue.front().second == time){
                pq.push(timeQueue.front().first);
                timeQueue.pop_front();
            }
        }
        return time;
    }
};