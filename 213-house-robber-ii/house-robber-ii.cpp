class Solution {
public:
    int robHouse(vector<int> &nums,int s, int e){
        int prev1=0;int prev2=0;
        for (int i=s;i<=e;i++){
            int curr=max(prev1, prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1){return nums[0];}
        else if(n==2){return max(nums[0],nums[1]);}
        return max(robHouse(nums,0,n-2),robHouse(nums,1,n-1));
    }
};