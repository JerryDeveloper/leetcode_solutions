class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counter;
        for(const string& cpdomain: cpdomains) {
            istringstream iss(cpdomain);
            
            string countStr;
            getline(iss, countStr, ' ');
            int count = stoi(countStr);
            
            string domain;
            getline(iss, domain);
            
            int index = -1;
            do {
                counter[domain.substr(index + 1)] += count;
                index = domain.find('.', index + 1);
            } while(index != string::npos) ;
        }
        
        vector<string> res;
        res.reserve(counter.size());
        for(auto& p : counter) {
            res.push_back(to_string(p.second) + " " + p.first);
        }
        
        return res;
    }
};