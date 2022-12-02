class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> first;
        map<char, int> second;
        
        for(auto it : word1)
            first[it]++;
        
        for(auto it : word2)
            second[it]++;
        
        if(first.size() != second.size())
            return false;
        
        // check if chars are same on not
        auto it1 = first.begin();
        auto it2 = second.begin();
        while(it1 != first.end())
        {
            if(it1->first != it2->first)
                return false;
            it1++;
            it2++;
        }
        
        vector<int>countFirst;
        for(auto it : first)
            countFirst.push_back(it.second);
        
        vector<int>countSecond;
        for(auto it : second)
            countSecond.push_back(it.second);
        
        sort(countFirst.begin(), countFirst.end());
        sort(countSecond.begin(), countSecond.end());
        
        if(countFirst != countSecond)
            return false;
        
        return true;
    }
};