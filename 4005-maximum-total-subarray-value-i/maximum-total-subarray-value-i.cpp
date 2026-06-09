class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int l=0;
        int mx=0,mn=INT_MAX;
        int n=nums.size();
        while (l<n){
            mx=max(mx,nums[l]);
            mn=min(mn,nums[l]);
            l++;
        }
        return (long long)(mx-mn)*k;
    }
};