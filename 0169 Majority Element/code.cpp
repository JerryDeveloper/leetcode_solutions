class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majority_index = 0;
        int count = 1;
        
        for(int i = 1; i < num.size(); ++i)
        {
            num[majority_index] == num[i] ? ++count : --count;
            if(count == 0)
            {
                majority_index = i;
                count = 1;
            }
        }
        
        return num[majority_index];
    }

};