class Solution:
    def houses(self, nums: List[int],start : int, end : int) ->int:
        prev2=0
        prev1=0
        for i in range(start,end+1):
            curr=max(prev1,prev2+nums[i])
            prev2=prev1
            prev1=curr
        return prev1

    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        v1=self.houses(nums,0,n-2)
        v2=self.houses(nums,1,n-1)
        return max(v1,v2)

        