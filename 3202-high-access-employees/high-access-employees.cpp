class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, multiset<string>> mp;
        for(auto& it : access_times){
            mp[it[0]].insert(it[1]);
        }

        set<string>ret;
        for(auto& it : access_times){
            string key = it[0];
            string startTime = it[1];
            string endTime = to_string(stoi(startTime)+99);
            if(endTime.size()==3) endTime = '0' + endTime;
            auto low = mp[key].lower_bound(startTime);
            auto high = mp[key].upper_bound(endTime);
            if(distance(low,high)>=3)
                ret.insert(key);
        }
        return vector<string>(ret.begin(),ret.end());
    }
};