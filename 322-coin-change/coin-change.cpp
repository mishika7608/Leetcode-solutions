class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0){return 0;}
        // if (coins.size()==1){return amount==coins[0]?1:-1;}

        vector<int> dp(amount+1, 1e9);
        dp[0]=0;

        for (int c: coins){
            for (int a=c;a<=amount;a++){
                dp[a] = min(dp[a], 1+dp[a-c]);
            }
        }

        return dp[amount]==1e9?-1:dp[amount];
    }
};