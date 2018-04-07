ass Solution {
public:
    
    // count number of different types
    // result is min of total_num/2 and num of types
    
    int distributeCandies(vector<int>& candies) {
        set<int> diffTypes;
        for(const int& c : candies) {
            diffTypes.insert(c);
        }
        
        return min(candies.size() / 2, diffTypes.size());
    }
};
