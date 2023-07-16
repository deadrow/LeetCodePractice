class Solution {
public:
    vector<int> ret;
    vector<vector<int>>memo;
    void dp(vector<int>& peopleSkill, int mask, vector<int> curSet, int cur_i, int m)
    {
        if(cur_i == peopleSkill.size())
        {
            if(mask == (1 << m)-1)
            {
                if(ret.size() == 0 || curSet.size() < ret.size())
                    ret = curSet;
            }
            return;
        }
            
        if(memo[mask][cur_i] != -1)
            if(memo[mask][cur_i] <= curSet.size())
                return;

        dp(peopleSkill, mask, curSet, cur_i+1, m);  // leave
        curSet.push_back(cur_i);

        dp(peopleSkill, peopleSkill[cur_i] | mask, curSet, cur_i+1, m);  // take

        curSet.pop_back();

        if(curSet.size() > 0)
            memo[mask][cur_i] = curSet.size();
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();

        memo.resize(1<<m, vector<int>(n, -1));

        unordered_map<string,int> reqDict;
        for(int i=0;i<m;i++)
            reqDict[req_skills[i]] = 1 << i;

        vector<int>peopleSkill;

        for(auto it : people)
        {
            int mask = 0;
            for(auto it1 : it)
            {
                if(reqDict.count(it1))
                    mask |= reqDict[it1];
            }

            peopleSkill.push_back(mask);
        }

        vector<int> curSet;
        dp(peopleSkill, 0, curSet, 0, m);
        return ret;
    }
};