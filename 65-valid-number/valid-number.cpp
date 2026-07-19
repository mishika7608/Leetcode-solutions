class Solution {
public:
    bool isNumber(string s) {
        bool dot=false,e=false,dig=false;
        int n=s.size();
        for (int i=0;i<n;i++){
           if (isdigit(s[i])){
                dig=true;
           }else if(s[i]=='e' || s[i]=='E'){
                if (e || !dig){return false;}
                e=true;
                dig=false;
           }else if (s[i]=='.'){
                if (e || dot){return false;}
                dot=true;
           }else if (s[i]=='+' || s[i]=='-'){
                if (i!=0 && s[i-1]!='e' && s[i-1]!='E'){return false;}
           }else{
                return false;
           }
        }
        return dig;
    }
};