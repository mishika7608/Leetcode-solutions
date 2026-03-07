class Solution {
public:

    string expand(string &s,int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }

    string longestPalindrome(string s) {
        string ans="";

        for(int i=0;i<s.size();i++){

            string odd=expand(s,i,i);
            if(odd.size()>ans.size()) ans=odd;

            string even=expand(s,i,i+1);
            if(even.size()>ans.size()) ans=even;
        }

        return ans;
    }

     
    // BRUTE FORCE
    // pair<string,int> check(string s, int b, int e){
    //     int n = s.size();
    //     string ans;
    //     int v=e+1-b;
    //     for (int i=b;i<=e;i++){
    //         ans+=s[i];}
    //     while (b<=e){
    //         if (s[b]!=s[e]){return {"",0};}
    //         b++;e--;
    //     }
    //     return {ans,v};
    // }
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     string ans;
    //     int mx=0;
    //     for (int i=0;i<n;i++){
    //         for (int j=i+1;j<n;j++){
    //             auto [str, val] = check(s,i,j);
    //             if (mx<val){mx=val;ans=str;}
    //         }
    //     }
    //     return ans;
    // }
};