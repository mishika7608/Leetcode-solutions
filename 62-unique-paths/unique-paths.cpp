class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0]=1;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (dp[i][j]==0){
                    int v1=0,v2=0;
                    if (i!=0){v1=dp[i-1][j];}
                    if (j!=0){v2=dp[i][j-1];}
                    dp[i][j]=v1+v2;
                }
            }
        }return dp[m-1][n-1];
    }
};