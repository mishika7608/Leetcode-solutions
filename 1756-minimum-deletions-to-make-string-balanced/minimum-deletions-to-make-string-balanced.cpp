class Solution {
public:
    int minimumDeletions(string s) {
        int del=0;
        int bcnt=0;
        int n = s.size();
        for (char c: s){
            if (c=='b'){bcnt++;}
            else if (c=='a'){del = min(del+1,bcnt);}
        }return del;
    }
};