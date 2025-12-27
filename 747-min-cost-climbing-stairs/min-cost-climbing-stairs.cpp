class Solution {
public:
    int calcMin(vector<int> &cost, int i,vector<int> &dp){
        if (i>=cost.size()){return 0;}
        if (dp[i]!=-1){return dp[i];}
        int step1 = cost[i]+calcMin(cost,i+1,dp);
        int step2 = cost[i]+calcMin(cost,i+2,dp);
        return dp[i] = min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(calcMin(cost,0,dp),calcMin(cost,1,dp));
    }
};