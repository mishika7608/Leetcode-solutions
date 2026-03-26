class Solution {
public:
    int helper(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0;
        for (int i = l; i <= r; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(helper(nums, 0, n - 2),helper(nums, 1, n - 1));
    }
};


// class Solution {
// public:
//     int maxLoot(int i, int n, vector<int> &memo, vector<int> &nums){
//         if (i>=n){return 0;}
//         if (memo[i]!=-1){return memo[i];}
//         int rob = nums[i]+maxLoot(i+2,n,memo,nums);
//         int skip = maxLoot(i+1,n,memo,nums);
//         memo[i]=max(rob, skip);
//         return memo[i];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n==1){return nums[0];}
//         vector<int> memo1(n,-1), memo2(n,-1);
//         return max(maxLoot(1,n,memo1,nums),maxLoot(0,n-1,memo2,nums));
//     }
// };