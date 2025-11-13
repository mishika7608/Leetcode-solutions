class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        vector<char> stack;
        int top=-1;
        for (int i=0;i<n;i++){
            if (s[i]=='(' || s[i]=='{' || s[i]=='['){
                top++;
                stack.push_back(s[i]);
            }
            else if (top>=0 && s[i]==')'){
                if (stack[top]=='('){
                    stack.pop_back();
                    top--;
                }else{return false;}
            }
            else if (top>=0 && s[i]==']'){
                if (stack[top]=='['){
                    stack.pop_back();
                    top--;
                }else{return false;}
            }
            else if (top>=0 && s[i]=='}'){
                if (stack[top]=='{'){
                    stack.pop_back();
                    top--;
                }
                else{return false;}
            }
            else{
                return false;
            }
        }
        if (stack.size()==0){
            return true;
        }
        return false;
    }
};
