class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int s=nums[0];
        int prof=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]<s){s=nums[i];}
            if (nums[i]>s){prof=max(prof,nums[i]-s);}
        }
        return prof;
    }
};