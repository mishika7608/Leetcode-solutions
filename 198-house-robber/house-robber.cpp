class Solution {
public:
    // DP - Iterative
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> memo(n,0);
    //     for (int i=0;i<n;i++){
    //         if (i==0 || i==1){memo[i]=nums[i];}
    //         else{
    //             int mx=0;
    //             for (int j=0;j<i-1;j++){mx=max(mx,nums[i]+memo[j]);}
    //             memo[i]=mx;
    //         }
    //     }
    //     int mx=0;
    //     for (int j=0;j<n;j++){mx=max(mx,memo[j]);}
    //     return mx;
    // }
    
    // DP - Recursive
    int maxLoot(int i,int n,vector<int> &memo, vector<int> &nums){
        if (i>=n){return 0;}
        if (memo[i]!=-1){return memo[i];}
        int rob = nums[i]+maxLoot(i+2,n,memo,nums);
        int skip = maxLoot(i+1,n,memo,nums);
        memo[i]=max(rob, skip);
        return memo[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,-1);
        return maxLoot(0,n,memo,nums);
    }
};