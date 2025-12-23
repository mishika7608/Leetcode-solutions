class Solution {
public:
    int maxLoot(int i, int n, vector<int> &memo, vector<int> &nums){
        if (i>=n){return 0;}
        if (memo[i]!=-1){return memo[i];}
        int rob = nums[i]+maxLoot(i+2,n,memo,nums);
        int skip = maxLoot(i+1,n,memo,nums);
        memo[i]=max(rob, skip);
        return memo[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){return nums[0];}
        vector<int> memo1(n,-1), memo2(n,-1);
        return max(maxLoot(1,n,memo1,nums),maxLoot(0,n-1,memo2,nums));
    }
};