ass Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, int> counter;
        for(int n : nums1) {
            ++counter[n];
        }
        
        vector<int> res;
        for(int n : nums2) {
            if(counter.find(n) != counter.end() && counter[n] > 0) {
                res.push_back(n);
                --counter[n];
            }
        }
        
        return res;
    }
};
