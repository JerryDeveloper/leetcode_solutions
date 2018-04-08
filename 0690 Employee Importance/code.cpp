/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, const Employee*> empMap;
        const Employee* target = nullptr;
        for(const Employee* e : employees) {
            empMap[e->id] = e;
            if(e->id == id) {
                target = e;
            }
        }
        
        if(target == nullptr)
            return 0;
        
        int res = 0;
        queue<const Employee*> q;
        q.push(target);
        while(!q.empty()) {
            const Employee* temp = q.front();
            q.pop();
            
            res += temp->importance;
            
            for(const int& s : temp->subordinates)
                q.push(empMap[s]);
        }
        
        return res;
    }
};