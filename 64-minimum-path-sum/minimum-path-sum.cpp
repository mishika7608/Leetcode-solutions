class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));

        dp[0][0]=grid[0][0];

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i!=0 || j!=0){
                int v1=INT_MAX,v2=INT_MAX;
                if (i>0){v1 = dp[i-1][j] + grid[i][j];}
                if (j>0){v2 = dp[i][j-1] + grid[i][j];}
                dp[i][j] = min(v1,v2);}
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                cout << dp[i][j] << " ";
            }cout<<endl;
        }

        return dp[m-1][n-1];
    }
};