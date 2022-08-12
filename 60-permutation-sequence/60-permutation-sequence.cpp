class Solution {
public:
    string ans;
    int k;
    void permute(string num, int cur)
    {
        if(cur == num.size()-1)
        {
            k--;
            if(k == 0)
                ans = num;
            return;
        }

        sort(num.begin()+cur, num.end());
        for(int i=cur;i<num.size();i++)
        {
            swap(num[i], num[cur]);
            permute(num, cur+1);
            swap(num[i], num[cur]);
        }
        
    }
    
    string getPermutation(int n, int k)
    {
        this->k = k;
        string num;
        for(int i=1;i<=n;i++)
            num += i + '0';
        
        permute(num, 0);
        return ans;
    }
};