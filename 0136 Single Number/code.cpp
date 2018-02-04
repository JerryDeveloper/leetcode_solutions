class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // a XOR a = 0
        // 0 XOR a = a
        // a XOR b = b XOR a
        // a XOR b XOR c = a XOR (b XOR c)

        int res = 0;
        for(int i : nums)
            res = res ^ i;
        return res;
    }
};