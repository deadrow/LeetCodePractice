class Solution {
public:
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ret;
        ret.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= ret.back()[1]) {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            } else
                ret.push_back(intervals[i]);
        }

        return ret;
    }

    // line sweep
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        vector<vector<int>>ret;
        map<int,int>dict;
        for(auto it : intervals){
            dict[it[0]] += 1;
            dict[it[1]] -= 1;
        }

        int start = -1;
        int end = -1;
        int count=0;
        for(auto& [key,value] : dict){
            if(count==0)
                start = key;
            count += value;
            if(count==0){
                end = key;
                ret.push_back({start, end});
            }
        }
        return ret;
    }
    
    // merge with map
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ret;
        map<int,int>dict;
        for(auto it : intervals){
            auto end = dict.lower_bound(it[0]);
            if(end != dict.end()){
                int s = end->second;
                int e = end->first;
                if(it[0] > e){
                    dict[it[1]]=it[0];
                } else{
                    dict.erase(e);
                    dict[max(it[1], e)] = min(it[0], s);
                }
            } else {
                dict[it[1]]=it[0];
            }
        }

        for(auto it : dict){
            ret.push_back({it.second, it.first});
        }
        return ret;
    }
};