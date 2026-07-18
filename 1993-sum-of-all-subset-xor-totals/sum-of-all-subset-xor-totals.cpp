class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int OR=0;
        for (int x : nums){
            OR|=x;
        }
        int n=nums.size();
        return OR*(1<<(n-1));
    }
};