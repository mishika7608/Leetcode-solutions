class Solution {
public:
    int mod = 1e9+7;
    int knightDialer(int n) {
        vector<vector<int>> moves = {
            {4,6}, {6,8}, {7,9}, {4,8},
            {0,3,9}, {}, {0,1,7},
            {2,6}, {1,3}, {2,4}
        };
        vector<long long> dp(10,1);
        for (int step = 2; step <= n; step++) {
            vector<long long> temp(10,0);
            for (int i = 0; i < 10; i++) {
                for (int j : moves[i]) {
                    temp[i] = (temp[i] + dp[j]) % mod;
                }
            }
            dp = temp;
        }
        long long ans = 0;
        for (auto x : dp) ans = (ans + x) % mod;
        return ans;
    }
};