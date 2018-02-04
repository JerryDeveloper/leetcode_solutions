class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // time O(n), space O(k). maintain a set of last k elements. if current element is in the set, return true.
        
        int lens = nums.size();
        k = min(lens - 1, k); // max distance cannot exceed nums.size() - 1
        
        unordered_set<int> last_k;
        
        for(int i = 0; i < lens; ++i)
        {
            if(i >= k + 1)
                last_k.erase(nums[i - k - 1]);
            
            if(last_k.count(nums[i]) > 0)
                return true;
            
            last_k.insert(nums[i]);
        }
        
        return false;
    }
};