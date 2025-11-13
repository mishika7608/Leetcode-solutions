class Solution {
public:
    bool isPalindrome(string s) {
        string st;
        int k=0;
        while (k<s.size()){
            if (s[k]>='a' && s[k]<='z'){
                st+=s[k];}
            else if (s[k]>='A'&& s[k]<='Z'){
                st+=(s[k]+32);
            }
            else if (s[k]>='0' && s[k]<='9'){
                st+=s[k];}
            k++;
        }
        string rev=st;
        int j=0;
        int flag=0;
        for (int i=st.size()-1;i>=0 && j<st.size();i--){
            if (rev[j]!=st[i]){flag=1;break;}
            j++;
        }
        if (flag){return false;}
        else{return true;}
    }
};
