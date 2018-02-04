class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(')
                st.push(')');
            else if(c == '[')
                st.push(']');
            else if(c == '{')
                st.push('}');
            else {
                if(st.empty() || c != st.top())
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};