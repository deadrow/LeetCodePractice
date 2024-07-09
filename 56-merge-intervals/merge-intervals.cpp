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
        vector<vector<int>>ret;
        set<pair<int, int>> st;
        for(auto itr : intervals){
            int left = itr[0], right = itr[1];
            auto it = st.upper_bound({left, INT_MIN});
            if(it != st.begin() && (--it)->second < left) {
                ++it;
            }
            
            while(it != st.end() && it->first <= right) {
                left = min(left, it->first);
                right = max(right, it->second);
                it = st.erase(it);
            }
            
            st.insert({ left, right });
        }

        for(auto it : st){
            ret.push_back({it.first, it.second});
        }
        return ret;
    }
};