class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate=0;
        int n = nums.size()-1;
        for (int i=0;i<32;i++){
            int cnt=0,cntRange=0;
            int mask=1<<i;
            for (int x : nums){if (x & mask)cnt+=1;}
            for (int k=1;k<=n;k++){
               if (mask & k) cntRange+=1;
            }
            if (cntRange<cnt){duplicate|=mask;}
        }
        return duplicate;
    }
};