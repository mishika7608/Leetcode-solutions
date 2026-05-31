class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left=0;
        int len=INT_MAX;
        for (int right=0;right<nums.size();right++){
            sum+=nums[right];
            while (sum >= target){
                len=min(len,right-left+1);
                sum-=nums[left++];
            }
        }
        return len==INT_MAX?0:len;
    }
};