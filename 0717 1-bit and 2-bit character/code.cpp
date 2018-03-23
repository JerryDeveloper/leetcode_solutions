ass Solution {
public:
    
    // any string with even number of chars can always be constructed with 
    
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 0 || bits[bits.size() - 1] == 1)
            return false;
        
        if(bits.size() == 1 || bits[bits.size() - 2] == 0)
            return true;
        
        // after removing last two char '10'. if remaining is valid, then return false, else return true
        bool prevOne = false;
        for(int i = 0; i < bits.size() - 2; ++i) {
            if(prevOne)
                prevOne = false;
            else if(bits[i] == 1) 
                prevOne = true;
        }
        
        // the only invalid case is when last bit is 1
        return prevOne;
    }
};
