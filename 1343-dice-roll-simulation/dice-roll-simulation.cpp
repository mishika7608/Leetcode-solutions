class Solution {
public:
    int mod = 1e9+7;
    int dp[5001][7][16];

    int solve(int n, int last, int count, vector<int>& rollMax) {
        if (n == 0) return 1;

        if (dp[n][last][count] != -1)
            return dp[n][last][count];

        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            if (i == last && count == rollMax[i-1]) continue;

            if (i == last)
                ans = (ans + solve(n-1, i, count+1, rollMax)) % mod;
            else
                ans = (ans + solve(n-1, i, 1, rollMax)) % mod;
        }
        return dp[n][last][count] = ans;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0, rollMax);
    }
};