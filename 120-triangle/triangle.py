class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n=len(triangle)
        dp=[]
        for i in range(1,n+1):
            dp.append([0]*i)
        for i in range(n):
            dp[n-1][i]=triangle[n-1][i]
        row=n-2
        while row>=0:
            for i in range(row+1):
                v1=triangle[row][i]+dp[row+1][i]
                v2=triangle[row][i]+dp[row+1][i+1]
                dp[row][i]=min(v1,v2)     
            row-=1; 
        return min(dp[0])