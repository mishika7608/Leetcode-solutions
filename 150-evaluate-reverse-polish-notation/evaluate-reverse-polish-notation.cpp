class Solution {
public:
    int calc(int a, int b, string c){
        if (c=="+"){
            return a+b; 
        }
        else if (c=="-"){
            return a-b; 
        }
        else if (c=="*"){
            return a*b; 
        }
        else{
            if (a==0 || b==0){return 0;}
            return a/b; 
        }return 0;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i=0;i<n;i++){
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int val=calc(a,b,tokens[i]);
                st.push(val);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};