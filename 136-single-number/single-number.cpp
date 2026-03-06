class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums){
            xorAll ^= x;
        }return xorAll;
    }
};