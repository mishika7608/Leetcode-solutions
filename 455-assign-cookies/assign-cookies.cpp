class Solution {
public:
    //DP
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(g.begin(), g.end());
    //     sort(s.begin(), s.end());
    //     int n = g.size();
    //     int m = s.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    //     for (int i=1;i<=n;i++){
    //         for (int j=1;j<=m;j++){
    //             dp[i][j]= max(dp[i-1][j], dp[i][j-1]);

    //             if (s[j-1]>=g[i-1]){
    //                 dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }


    // GREEDY
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