class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorAll=0;
        for (int i=0;i<=nums.size();i++){xorAll^=i;}
        for (int x : nums){xorAll^=x;}
        return xorAll;
    }
};