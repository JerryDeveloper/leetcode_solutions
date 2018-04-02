class Solution {
public:
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        
        for(auto p1 = points.begin(); p1 != points.end(); ++p1) {
            map<int, int> counter;
            for(auto p2 = points.begin(); p2 != points.end(); ++p2) {
                if(p1 == p2)
                    continue;
                
                int dist = pow((p1->first - p2->first), 2) + pow((p1->second - p2->second), 2);
                ++counter[dist];
            }
            
            for(auto c : counter) {
                result += c.second * (c.second - 1);
            }
        }
        
        return result;
    }
};
