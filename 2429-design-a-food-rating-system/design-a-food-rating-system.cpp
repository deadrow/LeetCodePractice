struct Data{
    string food;
    string cuisine;
    int rating=0;
    Data()= default;
    Data(const string& food, const string& cuisine, int rating):food(food), cuisine(cuisine), rating(rating){}

    bool operator < (const Data& first) const {
        if(rating != first.rating)
            return rating > first.rating;
        return food < first.food;
    }
};

class FoodRatings {
public:
    unordered_map<string, Data>foodToInfo;
    unordered_map<string,set<Data>>cuisingToInfo;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            Data d(foods[i], cuisines[i], ratings[i]);
            foodToInfo[foods[i]] = d;
            cuisingToInfo[cuisines[i]].insert(d);
        }
    }
    
    void changeRating(string food, int newRating) {
        Data& d = foodToInfo[food];
        cuisingToInfo[d.cuisine].erase(d);
        d.rating = newRating;
        cuisingToInfo[d.cuisine].insert(d);
    }
    
    string highestRated(string cuisine) {
        return cuisingToInfo[cuisine].begin()->food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */