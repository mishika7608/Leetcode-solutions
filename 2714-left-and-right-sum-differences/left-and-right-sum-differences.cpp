class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> lsum(n,0);
        vector<int> rsum(n,0);
        int left=0;
        int right=0;
        for (int i=0;i<n;i++){
            lsum[i]=left;
            rsum[n-i-1]=right;
            right+=nums[n-1-i];
            left+=nums[i];
        }
        for (int i=0;i<n;i++){
            nums[i]=abs(lsum[i]-rsum[i]);
        }
        return nums;
    }
};