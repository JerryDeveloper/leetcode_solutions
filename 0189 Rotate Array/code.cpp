class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int lens = nums.size();
        int processed_k = k % lens;
        reverse(nums.begin(), nums.begin() + lens - processed_k);
        reverse(nums.begin() + lens - processed_k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};