class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;

        int totalSum = 0;
        for(auto it : salary)
        {
            totalSum += it;
            minSalary = min(it, minSalary);
            maxSalary = max(it, maxSalary);
        }

        totalSum -= minSalary;
        totalSum -= maxSalary;
        return (double)totalSum / (salary.size()-2);
        
    }
};