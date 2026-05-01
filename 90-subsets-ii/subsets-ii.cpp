class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, vector<int> &temp, int ind){
        res.push_back(temp);
        for (int i=ind;i<nums.size();i++){
            if (i>ind && nums[i-1]==nums[i]){continue;}
            temp.push_back(nums[i]);
            helper(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums,temp,0);
        return res;
    }
};