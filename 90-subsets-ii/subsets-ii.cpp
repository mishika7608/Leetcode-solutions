class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> nums, vector<int> temp, int ind){
        res.push_back(temp);
        for (int i=ind;i<nums.size();i++){
            if (i>ind && nums[i]==nums[i-1]){continue;}
            temp.push_back(nums[i]);
            helper(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums,temp,0);
        return res;
    }
};