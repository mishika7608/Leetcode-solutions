class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XORAll = 0;
        for (int i : nums){
            XORAll^=i;
        }
        return XORAll;
    }
};