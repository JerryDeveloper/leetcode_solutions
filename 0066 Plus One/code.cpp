class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(auto pt = digits.end() - 1; pt != digits.begin() - 1; --pt)
        {
            int sum = carry + (*pt);
            *pt = sum % 10;
            carry = sum / 10;
        }
        
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};