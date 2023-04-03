class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        if(n < 2)
            return 1;
        
        sort(people.begin(), people.end());
        
        int boats = 0;
        int i = 0;
        int j = n-1;
        
        if(people[i] >= limit)
            return n;
        
        while(i<=j)
        {
            if(people[j]>= limit || people[i]+people[j] > limit)
            {
                boats++;
                j--;
            }
            else
            {
                boats++;
                i++;
                j--;
            }
        }
        return boats;
    }
};