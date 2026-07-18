class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr=0;
        for (int i : nums){
            xr ^= i;
        }
        int n1=0,n2=0;
        int diff=xr &(-xr);
        for (int i : nums){
            if (diff & i){
                n1^=i;
            }else{
                n2^=i;
            }
        }
        return {n1,n2};
    }
};