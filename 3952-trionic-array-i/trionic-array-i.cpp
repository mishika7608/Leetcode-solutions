class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=0,n=nums.size();
        while (p<n-2 && nums[p]<nums[p+1]){
            p+=1;
        }
        if (p==0){return false;}
        int q=p;
        while (q<n-1 && nums[q]>nums[q+1]){
            q+=1;
        }
        if (p==q || q==n-1){return false;}

        while (q<n-1 && nums[q]<nums[q+1]){q+=1;}
        
        return q==n-1;
    }
};