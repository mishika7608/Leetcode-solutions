class Solution {
public:
    //DP
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for (int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1], dp[i][0]-prices[i]);
        }
        return dp[n-1][0];
    }


    // BRUTE FORCE
    // int maxProfit(vector<int>& prices) {
    //     int ans=0;
    //     for (int i=0;i<prices.size()-1;i++){
    //         int sum=0;
    //         int start=i;
    //         for (int j=i+1;j<prices.size();j++){
    //             if (prices[j]>prices[start]){
    //                 sum+=(prices[j]-prices[start]);
    //                 start=j;
    //             }
    //             if (sum>0){
    //             if (prices[j]<prices[start]){
    //                 start=j;
    //             }}
    //         }
    //         ans=max(ans,sum);
    //     }
    //     return ans;
    // }

    //GREEDY
    // bool isInc(vector<int>& prices){
    //     for (int i=1;i<prices.size();i++){
    //         if (prices[i]<prices[i-1]){return false;}
    //     }return true;
    // }
    // int maxProfit(vector<int>& prices) {
    //     if (isInc(prices)) return prices[prices.size()-1]-prices[0];
    //     int mn=INT_MAX;
    //     int ans = 0;
    //     for (int i=0;i<prices.size();i++){
    //         mn= min(mn,prices[i]);
    //         if (i>0 && (prices[i]-prices[i-1])<0){mn=prices[i];}
    //         if (i<prices.size()-1 && prices[i+1]>=prices[i]){}
    //         else{
    //         ans += prices[i]-mn;}
    //     }
    //     return ans;
    // }
};