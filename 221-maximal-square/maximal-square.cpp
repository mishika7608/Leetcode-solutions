class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n,0);
        int prev=0, ans=0;

        for (int i=0;i<m;i++){
            prev=0;
            for (int j=0;j<n;j++){
                int temp=dp[j];
                if (matrix[i][j]=='1'){
                    dp[j]=1+min({dp[j],j>0?dp[j-1]:0,prev});
                    int v = (dp[j]*dp[j]);
                    ans=max(ans, v);
                }
                else{
                    dp[j]=0;
                }
                prev=temp;
            }
        }
        return ans;
    }
};