class Solution {
public:
    
    // tree level 1: place of first cut, level 2: place of second cut, level 3, third cut
    
    // cut_point[]: index of numbers before cut, so [0, s.size() - 2]. e.g. (-1, 3, 4) when level = 2
    void restoreIpAddressUtil(const string s, int level, int cut_points[], vector<string> & res) {
        if(level >= 4)
            return; // max 3 cuts
        
        if(level == 3) {
            // search last valid cut_point and form solution
            for(int i = cut_points[level - 1] + 1; i < s.size() - 4 + level; ++i) {
                string third_por = s.substr(cut_points[level - 1] + 1, i - cut_points[level - 1]);
                int third_por_s = third_por.size();
                if(third_por_s > 3 || third_por_s <= 0 || (third_por_s > 1 && third_por[0] == '0') || stoi(third_por) > 255)
                    break;
                string forth_por = s.substr(i + 1);
                int forth_por_s = forth_por.size();
                if(forth_por_s > 3 || forth_por_s <= 0 || (forth_por_s > 1 && forth_por[0] == '0') || stoi(forth_por) > 255)
                    continue;
                
                res.push_back(s.substr(0, cut_points[1] + 1) + "." + s.substr(cut_points[1] + 1, cut_points[2] - cut_points[1]) + 
                              "." + s.substr(cut_points[2] + 1, i - cut_points[2]) + "." + s.substr(i + 1));
            }
        }
        else {
            // search current valid cut_point and go to next level
            for(int i = cut_points[level - 1] + 1; i < s.size() - 4 + level; ++i) {
                string cur_por = s.substr(cut_points[level - 1] + 1, i - cut_points[level - 1]);
                int cur_por_s = cur_por.size();
                if(cur_por_s > 3 || cur_por_s <= 0 || (cur_por_s > 1 && cur_por[0] == '0') || stoi(cur_por) > 255)
                    break;
                
                cut_points[level] = i;
                restoreIpAddressUtil(s, level + 1, cut_points, res);
            }
        }
        
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        
        if(s.size() < 4)
            return res;
        
        int cut_points[3] = {-1, -1, -1};
        restoreIpAddressUtil(s, 1, cut_points, res);
        
        return res;
    }
};