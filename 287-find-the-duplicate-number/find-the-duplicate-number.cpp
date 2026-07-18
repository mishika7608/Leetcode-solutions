class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int duplicate=0;
        for (int bit=0;bit<32;bit++){
            int mask = 1<<bit;
            int cntNums=0;int cntRange=0;
            for (int n : nums){if (n&mask){cntNums++;}}
            for (int i=1;i<=n;i++){
                if (i&mask){cntRange++;}            }
            if (cntNums > cntRange){duplicate+=mask;}
        }
        return duplicate;
        
    }
};