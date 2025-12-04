class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (n==1 && m==1){return obstacleGrid[0][0]==0;}

        if (n==1 ){for (int i=0;i<m;i++){if(obstacleGrid[0][i]==1){return 0;}}return 1;} 

        if (m==1 ){for (int i=0;i<n;i++){if(obstacleGrid[i][0]==1){return 0;}}return 1;} 
        
        
        vector<vector<long long>> dp(n, vector<long long>(m,0));
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0]=1;
        for (int i=0; i<n;i++)
        {
            for (int j=0;j<m;j++){
                if (obstacleGrid[i][j]==1){dp[i][j]=0;continue;}

                if (i>0){dp[i][j] += dp[i-1][j];}
                if (j>0){dp[i][j] += dp[i][j-1];}
            }
        }
        return dp[n-1][m-1];
    }
};