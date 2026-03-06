class Solution {
public:
    bool isPalin(string &s, int i, int j){
        while (i<j){
            if (s[i++]!=s[j--])return false;
        }return true;
    }
    void helper(vector<vector<string>> &res, vector<string> &temp, int i, string &s){
        if (i==s.size()){res.push_back(temp);return ;}
        for (int j=i;j<s.size();j++){
            if (isPalin(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                helper(res,temp,j+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        helper(res, temp, 0,s);
        return res;
    }
};