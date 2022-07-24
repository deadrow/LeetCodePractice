class FoodRatings {
public:
    struct cmp
    {
        bool operator()(pair<int, string> a, pair<int, string> b) const
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    
    map<string,set<pair<int,string>,cmp>> cuisineFoods;
    map<string, string> food_cuisines;
    map<string, int> foodRatings;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            cuisineFoods[cuisines[i]].insert({ratings[i],foods[i]});
            food_cuisines[foods[i]] = cuisines[i];
            foodRatings[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisine = food_cuisines.find(food)->second;
        cuisineFoods[cuisine].erase({foodRatings[food], food});
        cuisineFoods[cuisine].insert({newRating, food});
        foodRatings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */