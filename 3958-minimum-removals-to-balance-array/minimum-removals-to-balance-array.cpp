class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int rem=0,i=0;
        for(int j=0;j<n;j++){
            while ((long)nums[j]>(long)nums[i]*k){i++;}
            rem=max(rem,(j-i+1));
        }
        return n-rem;
    }
};