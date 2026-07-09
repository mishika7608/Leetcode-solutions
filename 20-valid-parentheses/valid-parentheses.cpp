class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char i : s){
            if (i=='(' || i=='[' || i=='{'){
                st.push(i);
            }
            else{
                if (i==')'){
                    if (st.empty() || st.top()=='[' || st.top()=='{'){return false;}
                    else{st.pop();}
                } else if (i==']'){
                    if (st.empty() || st.top()=='(' || st.top()=='{'){return false;}
                    else{st.pop();}
                }else{
                    if (st.empty() || st.top()=='[' || st.top()=='('){return false;}
                    else{st.pop();}
                }
            }
        }
        return st.empty();
    }
};