class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1, 0);

        for (int i=n-1;i>=0;i--){
            int c1 = costs[0]+dp[i+1];
            int j=i;
            while (j<n && days[j]<days[i]+7){ j++;}
            int c2 = costs[1]+dp[j];
            int k=i;
            while (k<n && days[k]<days[i]+30) {k++;}
            int c3 = costs[2]+dp[k];
            dp[i]=min({c1,c2,c3});
        }

        return dp[0];
    }
};