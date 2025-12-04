class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for (int i=0;i<n;i++){
            vector<int> temp;
            for (int j=0;j<triangle[i].size();j++){
                temp.push_back(0);
            }
            dp.push_back(temp);
        }

        dp[0][0]=triangle[0][0];

        for (int i=1;i<n;i++){
            for (int j=0;j<triangle[i].size();j++){
                if (j==0){dp[i][j] = triangle[i][j]+dp[i-1][j];}
                else if (j==(triangle[i].size()-1)){
                    dp[i][j] = triangle[i][j]+dp[i-1][j-1];}
                else{
                    int v1 =INT_MAX, v2=INT_MAX;
                    v1 = triangle[i][j]+dp[i-1][j-1];
                    v2 = triangle[i][j]+dp[i-1][j];
                    dp[i][j]= min(v1,v2);
                }
            }
        }
        int ans=INT_MAX;
        for (int i=0;i<triangle[n-1].size();i++){
            ans= min(ans,dp[n-1][i]);
        }
        return ans;
    }
};