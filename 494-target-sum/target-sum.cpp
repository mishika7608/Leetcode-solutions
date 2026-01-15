class Solution {
public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum=0;
    //     for (int x: nums){sum+=x;}

    //     if (sum<abs(target) || (sum+target)%2!=0) return 0;

    //     int P=(sum+target)/2;
    //     vector<int> dp(P+1, 0);
    //     dp[0]=1;

    //     for (int x : nums){
    //         for (int s=P;s>=x;s--){
    //             dp[s] += dp[s-x];
    //         }
    //     }
    //     return dp[P];
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums){total+=num;}
        if (total<abs(target) || (total+target)%2!=0) return 0;
        int p = (total+target)/2;
        vector<int> dp(p+1,0);
        dp[0]=1;
        for (int num:nums){
            for (int s=p;s>=num;s--){
                dp[s] +=dp[s-num];
            }
        }
        return dp[p];

    }
};