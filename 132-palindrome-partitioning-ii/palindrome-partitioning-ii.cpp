class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> table(n, vector<bool> (n,false));
        for (int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                if (s[i]==s[j] && (j-i<=2 || table[i+1][j-1])){
                    table[i][j]=true;
                }
            }
        }
        vector<int> dp(n, INT_MAX);
        for (int i=0;i<n;i++){
            if (table[0][i]){dp[i]=0;}
            else{
                for (int j=0;j<i;j++){
                    if (table[j+1][i]){
                    dp[i]= min(dp[i], dp[j]+1);}
                }
            }
        }
        return dp[n-1];
    }

};