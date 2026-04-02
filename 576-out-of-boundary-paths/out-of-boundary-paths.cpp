class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];

    int solve(int m, int n, int k, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 1;
        if (k == 0) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        ans = (ans + solve(m,n,k-1,i+1,j)) % mod;
        ans = (ans + solve(m,n,k-1,i-1,j)) % mod;
        ans = (ans + solve(m,n,k-1,i,j+1)) % mod;
        ans = (ans + solve(m,n,k-1,i,j-1)) % mod;

        return dp[i][j][k] = ans;
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        memset(dp, -1, sizeof(dp));
        return solve(m,n,maxMove,i,j);
    }
};