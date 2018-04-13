class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counter;
        for(const string& cpdomain: cpdomains) {
            
            int count = 0;
            for(int i = 0; i < cpdomain.size(); ++i) {
                if(cpdomain[i] == ' ') {
                    count = stoi(cpdomain.substr(0, i + 1));
                    counter[cpdomain.substr(i + 1)] += count;
                }
                else if(cpdomain[i] == '.')
                    counter[cpdomain.substr(i + 1)] += count;
            }
        }
        
        vector<string> res;
        res.reserve(counter.size());
        for(auto& p : counter) {
            res.push_back(to_string(p.second) + " " + p.first);
        }
        
        return res;
    }
};