class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>data;
        for(int i=0;i<nums2.size();i++)
        {
            data.push_back({nums1[i], nums2[i]});
        }

        sort(data.begin(), data.end(), [](const auto& a, const auto& b) { return a.second > b.second;});

        priority_queue<int, vector<int>, greater<>>pq;
        long sum = 0;
        long ans = 0;
        for(auto [first, second] : data)
        {
            pq.push(first);
            sum += first;
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k)
                ans = max(ans, second*sum);
        }

        return ans;
    }
};