class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min_elem = nums[0];

        int curCount = 0;
        int ops = 0;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i] != nums[i-1])
            {
                curCount = n-i;
                ops += curCount;
                if(nums[i-1] == min_elem)
                    break;
            }
        }

        return ops;

        // priority_queue<int>pq;
        // for(auto it : nums)
        //     pq.push(it);

        // int sameCount = 0;
        // int ops = 0;
        // while(!pq.empty())
        // {
        //     int top = pq.top();
        //     pq.pop();

        //     while(pq.top() == top)
        //     {
        //         sameCount++;
        //         if(sameCount == n)
        //             return ops;
        //         pq.pop();
        //     }

        //     if(!sameCount)
        //     {
        //         ops++;
        //         sameCount++;
        //     }
        // }

        // return -1;
    }
};