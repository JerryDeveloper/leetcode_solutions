class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return {};
        
        vector<int> *cur = new vector<int>{1};
        if(rowIndex == 0)
        {
            vector<int> res = *cur;
            delete cur;
            return res;
        }
        
        vector<int> *prev = nullptr;
        for(int i = 1; i <= rowIndex; ++i)
        {
            if(prev != nullptr)
                delete prev;
            prev = cur;
            
            cur = new vector<int>(i + 1);
            (*cur)[0] = 1;
            (*cur)[i] = 1;
            
            for(int j = 1; j < i; ++j)
            {
                (*cur)[j] = (*prev)[j - 1] + (*prev)[j];
            }
        }
        
        if(prev != nullptr)
            delete prev;
        
        vector<int> res = *cur;
        delete cur;
        return res;
    }
};