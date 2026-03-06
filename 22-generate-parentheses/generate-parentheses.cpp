class Solution {
public:

    void genFunc(vector<string> &ans, int oc, int cc, int &n, string s){
        if (oc==n && cc==n){
            ans.push_back(s);
            return ;
        }
        if (oc<n)
        {
            genFunc(ans, oc+1, cc, n, s+'(');
        }
        if (cc<oc){
            genFunc(ans, oc, cc+1, n, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        int oc=0, cc=0;
        vector<string> ans;
        genFunc(ans,oc,cc,n,"");
        return ans;
    }
};