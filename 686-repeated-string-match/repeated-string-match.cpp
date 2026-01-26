class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string t="";
        int r=0;
        while (t.size()<b.size()+a.size()){ 
            t+=a;
            r++;
            if (t.find(b)!=string::npos){return r;}
        }return -1;
    }
};