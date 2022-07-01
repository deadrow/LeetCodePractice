/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> data;
    stack<NestedInteger> iterators;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->data = nestedList;
        for(int i= data.size()-1;i>=0;i--)
            iterators.push(data[i]);
    }
    
    int next() {
        if(!hasNext())
            return 0;
        
        int val = iterators.top().getInteger();
        iterators.pop();
        return val;
    }
    
    bool hasNext() {
        while(!iterators.empty() && !iterators.top().isInteger())
        {
            NestedInteger top = iterators.top();
            iterators.pop();
            for(int i= top.getList().size()-1;i>=0;i--)
                iterators.push(top.getList()[i]);
        }
        
        return !iterators.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */