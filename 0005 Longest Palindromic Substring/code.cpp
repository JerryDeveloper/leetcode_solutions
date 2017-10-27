class Solution {
public:
    string longestPalindrome(string s) {
        int start_index = 0;
        int max_len = 1;

        int k = 0;
        while(k < s.size())
        {
            if(s.size() - k < max_len / 2)
                break;

            int i = k;
            int j = k;

            while(j < s.size() - 1 && s[j] == s[j + 1])
                ++j;

            k = j + 1;
            
            while(i > 0 && j < s.size() - 1 && s[i - 1] == s[j + 1])
            {
                --i;
                ++j;
            }

            if(j - i + 1 > max_len)
            {
                start_index = i;
                max_len = j - i + 1;
            }
        }

        return s.substr(start_index, max_len);
    }
};