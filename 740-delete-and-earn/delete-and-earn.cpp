class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001, 0);
        for (int x : nums) {sum[x] += x;}

        int prev1 = 0, prev2 = 0;

        for (int i = 0; i <= 10000; i++) {
            int take = prev2 + sum[i];
            int skip = prev1;
            int cur = max(take, skip);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};