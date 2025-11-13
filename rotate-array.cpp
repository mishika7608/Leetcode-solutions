class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        long long int n=nums.size();
        vector<int> ints;
        if (k!=0 && n>k){
            reverse(nums.begin(),nums.end());
            reverse(nums.begin(),nums.begin()+k);
            reverse(nums.begin()+k,nums.end());
            k=0;
        }
        while (k>0){
            int ele=nums[n-1];
            for (long long i=n-2;i>=0;i--){
                nums[i+1]=nums[i];
            }
            nums[0]=ele;
            k--;
        }
    }
};
