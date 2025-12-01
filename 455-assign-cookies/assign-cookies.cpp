class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=s.size()-1;
        int ans=0;
        for (int i=g.size()-1;i>=0 && j>=0;i--){
            if (s[j]>=g[i]){j--;ans++;}
        }
        return ans;
    }
};