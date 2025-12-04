class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));

        for (int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for (int i=1;i<m;i++){
            for (int j=0;j<n;j++){
                int v1=INT_MAX,v2=INT_MAX,v3=INT_MAX;
                if (j-1>=0){v1 = dp[i-1][j-1] + matrix[i][j];}
                if (j+1<n){v3 = dp[i-1][j+1] + matrix[i][j];}
                v2 = dp[i-1][j] + matrix[i][j];
                int t = min(v1,v2);
                dp[i][j]= min(t,v3);
            }
        }

        int ans=INT_MAX;
        for (int i=0;i<n;i++){
            ans = min(ans,dp[m-1][i]);
        }

        return ans;
    }
};