class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto it : details)
            count += stoi(it.substr(11, 2)) > 60;
        return count;
    }
};