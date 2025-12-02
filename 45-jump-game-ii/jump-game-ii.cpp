class Solution {
public:
    int jump(vector<int>& nums) {
        int end=0;
        int far=0;
        int jump=0;
        int n= nums.size()-1;
        for (int i=0;i<n;i++){
            far = max(far,i+nums[i]);
            if (i==end){
                jump++;
                end=far;
            }
        }
        return jump;
    }
};