class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lens = numbers.size();
        
        for(int i = 0; i < lens; ++i)
        {
            int to_find = target - numbers[i];
            
            // binary search in remaining array
            int begin = i + 1;
            int end = lens - 1;
            
            while(begin <= end)
            {
                int mid = (begin + end) / 2;
                
                if(numbers[mid] == to_find)
                    return {i + 1, mid + 1};
                else if(numbers[mid] < to_find)
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
        }
        
        return {0, 0};
    }
};