class Solution {
public:
    // DP
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for (int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],-prices[i]);
        }return dp[n-1][0];
    }
    //GREEDY
    // int maxProfit(vector<int>& prices) {
    //     int mn=INT_MAX;
    //     int ans=0;

    //     for (int p: prices){
    //         mn= min(mn,p);
    //         ans= max(ans,p-mn);
    //     }
    //     return ans;
    // }
};