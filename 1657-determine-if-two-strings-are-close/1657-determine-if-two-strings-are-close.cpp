class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        map<char, int> first;
        map<char, int> second;
        
        for(auto it : word1)
            first[it]++;
        
        for(auto it : word2)
            second[it]++;
        
        if(first.size() != second.size())
            return false;
        
        if(!std::equal(first.begin(), first.end(), second.begin(), [](auto a, auto b) { return a.first == b.first;}))
            return false;
        
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