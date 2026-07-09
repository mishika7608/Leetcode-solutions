class Solution {
public:
    string helper(string str){
        char freq;
        string t;
        int s=0,e=1,n=str.size();
        while (e<n){
            if (str[s]==str[e]){e++;}
            else{
                freq=((e-s)+'0');
                t+=freq;t+=str[s];
                s=e;e+=1;
            }
        }
        freq=((e-s)+'0');
        t+=freq;t+=str[s];
        return t;
    }
    string countAndSay(int n) {
        string s="1";int i=1;
        while (i<n){
            s=helper(s);
            i++;
        }
        return s;
    }
};