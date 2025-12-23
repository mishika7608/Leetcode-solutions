class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,0);
        for (int i=0;i<n;i++){
            if (i==0 || i==1){memo[i]=nums[i];}
            else{
                int mx=0;
                for (int j=0;j<i-1;j++){mx=max(mx,nums[i]+memo[j]);}
                memo[i]=mx;
            }
        }
        int mx=0;
        for (int j=0;j<n;j++){mx=max(mx,memo[j]);}
        return mx;
    }
    // int maxLoot(vector<int> &nums, int i, vector<int> &memo){
    //     if (i>=nums.size()){return 0;}
    //     if (memo[i]!=-1){return memo[i];}
    //     int rob = nums[i]+maxLoot(nums, i+2,memo);
    //     int skip = maxLoot(nums, i+1, memo);
    //     memo[i] = max(skip, rob);
    //     return memo[i];
    // }
    // int rob(vector<int>& nums) {
    //     vector<int> memo(nums.size(), -1);
    //     return maxLoot(nums, 0, memo);
    // }
};