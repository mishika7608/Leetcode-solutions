class Solution {
public:
    int findMax(vector<int> &nums){
        int m=INT_MIN;
        int pos=-1;
        for (int i=0;i<nums.size();i++){
            if (m<nums[i]){
                m=nums[i];
                pos=i;
            }
        }
        return pos+1;
    }
    int findMin(vector<int> &nums){
        int m=INT_MAX;
        int pos=-1;
        for (int i=0;i<nums.size();i++){
            if (m>nums[i]){
                m=nums[i];
                pos=i;
            }
        }
        return pos+1;
    }
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        if (nums.size()==0 || nums.size()==1){
            return nums.size();
        }

        int Fmin=findMin(nums);
        int Fmax=findMax(nums);
        int Bmin=n-Fmin+1;
        int Bmax=n-Fmax+1;
        int ans=0;
        if (Fmin<Bmin && Fmax<Bmax){
            return max(Fmin,Fmax);
        }
        else if (Fmin>Bmin && Fmax>Bmax){
            return max(Bmin,Bmax);
        }
        else{
            ans= min(Fmin,Bmin)+min(Fmax,Bmax);
            if (ans>max(Fmin,Fmax)){return max(Fmin,Fmax);}
            else if(ans >max(Bmin,Bmax)){
                return max(Bmin,Bmax);
            }
            else{
                return ans;
            }
        }
    }
};
