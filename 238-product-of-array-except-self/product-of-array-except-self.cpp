class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre=1;int suf=1;
        vector<int> arr(nums.size(),1);
        int n=nums.size();
        for (int i=0;i<n;i++){
            arr[i]*=pre;
            arr[n-i-1]*=suf;
            pre*=nums[i];
            suf*=nums[n-i-1];
        }
        return arr;
    }
};