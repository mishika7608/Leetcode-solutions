class Solution {
public:
vector<vector<int>> res;
    void helper(vector<int> &nums,vector<int> temp, int ind){
        if (ind==nums.size()){res.push_back(temp);return ;}
        temp.push_back(nums[ind]);
        helper(nums,temp,ind+1);
        temp.pop_back();
        helper(nums,temp,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums,temp,0);
        return res;
    }
};