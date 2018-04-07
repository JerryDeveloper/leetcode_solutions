class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        
        map<string, int> indexes;
        
        for(int i = 0; i < list1.size(); ++i) {
            indexes[list1[i]] = i;
        }
        
        int minIndexes = INT_MAX;
        for(int i = 0; i < list2.size(); ++i) {
            if(indexes.find(list2[i]) == indexes.end())
                continue;
            
            int indexSum = i + indexes[list2[i]];
            if(indexSum < minIndexes) {
                res.clear();
                res.push_back(list2[i]);
                minIndexes = indexSum;
            }
            else if(indexSum == minIndexes)
                res.push_back(list2[i]);
        }
        
        return res;
    }
};