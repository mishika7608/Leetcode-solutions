class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression){
            if (c==',' || c=='(')continue;
            if (c!=')'){st.push(c);}
            else{
                bool hasTrue=false, hasFalse=false;
                while (st.top()!='!' && st.top()!='&' && st.top()!='|'){
                    if (st.top()=='t')hasTrue=true;
                    if (st.top()=='f')hasFalse=true;
                    st.pop();
                }
                char op=st.top();
                st.pop();
                char res;
                if (op=='!'){
                    res = hasTrue==true?'f':'t';
                }
                else if (op=='&'){
                    res= hasFalse==true?'f':'t';
                }
                else{
                    res = hasTrue==true?'t':'f';
                }
                st.push(res);
            }
        }return st.top()=='t';
    }
};