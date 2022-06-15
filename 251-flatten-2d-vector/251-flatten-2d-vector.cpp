class Vector2D {
public:
    int curRow = 0;
    int curCol = 0;
    vector<vector<int>> data;
    Vector2D(vector<vector<int>>& vec) {
        data = vec;
    }
    
    int next() {
        if(!hasNext()) throw std::out_of_range("blah");
        
        return data[curRow][curCol++];
    }
    
    void moveToNext()
    {
        while(curRow < data.size() && curCol == data[curRow].size())
        {
            curRow++;
            curCol = 0;
        }
    }
    
    bool hasNext() {
        moveToNext();

        if(curRow < data.size())
            return true;
        
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */