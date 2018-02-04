class Solution {
public:
    bool isAnagram(string s, string t) {
        // idea 1: sort both, and compare string. since both are chars. we can use counting sort. O(n)
        // idea 2: traverse both string and count occurance of each char. if both are same. they are anagram. O(n)
        // idea 2.1: only need to count one string, and when traversing the other string, decrease the count. at the end, if they are 
        // anagram, all count should be 0
        
        // implement idea 2.1
        
        unordered_map<char, int> counts;
        for(char i : s) ++counts[i];
        for(char i : t) --counts[i];
        for(auto iter: counts)
            if(iter.second != 0)
                return false;
        return true;
    }
};