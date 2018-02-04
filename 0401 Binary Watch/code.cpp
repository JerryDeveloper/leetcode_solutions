class Solution {
public:
    
    const int readingLength = 10;
    
    int binaryToDecimal(int *start, int *end, int length)
    {
        int res = 0;
        int i = 0;
        for(int *ptr = start; ptr <= end; ++ptr) {
            res += (*ptr) * pow(2, length - i - 1);
            ++i;
        }
        return res;
    }
    
    // backtracking: the tree is at root level, 1 to fill at spot 0, 1, 2,... 9. down to next level, 1 to fill at 1, 2, ...9 (under 0), 2, 3,..9 (under 1)
    
    // rem : remaining light to allocate
    // reading[10] : current reading record
    // curIndex : current slot in reading to fill
    void readBinaryWatchUtil(int rem, int curIndex, int reading[], vector<string> & res) {
        
        if(rem <= 0)
            return; // no slot to allocate
        
        if(curIndex >= readingLength)
            return;
        
        if(curIndex + rem > readingLength)
            return; // not enough slot to allocate remaining
        
        reading[curIndex] = 1; // after this, whenever return, need to set this spot back to 0 so that next spot can be allocated
        
        int hour = binaryToDecimal(&reading[0], &reading[3], 4);
        
        if(hour > 11)
        {
            // infeasible, current level move to next slot
            reading[curIndex] = 0;
            return;
        }
        
        int minute = binaryToDecimal(&reading[4], &reading[9], 6);
        
        if(minute > 59)
        {
            // infeasible, current level move to next slot
            reading[curIndex] = 0;
            return;
        }
        
        --rem; // successfully allocated one light
        
        if(rem == 0)
        {
            // all light allocated
            string hrStr = to_string(hour);
            string minStr = to_string(minute);
            if(minute < 10)
                minStr = "0" + minStr;
            res.push_back(hrStr + ":" + minStr);
            
            reading[curIndex] = 0;
            return;
        }
        
        // still have lights not allocated, continue traverse down the tree
        for(int i = curIndex + 1; i < readingLength; ++i)
            readBinaryWatchUtil(rem, i, reading, res);
        
        reading[curIndex] = 0;
        return;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        
        if(num == 0)
            res.push_back("0:00");
        
        int reading[readingLength];
        for(int i = 0; i < readingLength; ++i)
            reading[i] = 0;
        
        for(int curIndex = 0; curIndex < readingLength; ++curIndex)
            readBinaryWatchUtil(num, curIndex, reading, res);
        
        return res;
    }
};