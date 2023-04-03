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
                
        while(i<=j)
        {
            if(people[i]+people[j] <= limit)
                i++;
            j--;
            boats++;
        }
        return boats;
    }
};