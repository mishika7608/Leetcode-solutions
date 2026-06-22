class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum=0
        for i in nums:
            sum+=i
        if sum%2==1:
            return False
        target=sum//2
        dp=[False]*(target+1)
        dp[0]=True
        for num in nums:
            for s in range(target,num-1,-1):
                dp[s]=dp[s] or dp[s-num]
        return dp[target]
