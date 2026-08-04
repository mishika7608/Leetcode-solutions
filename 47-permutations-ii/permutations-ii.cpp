class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, vector<int> &temp, vector<bool> &used){
        if (nums.size()==temp.size()){res.push_back(temp);}
        for (int i=0;i<nums.size();i++){
            if (used[i]){continue;}
            if (i>0 && nums[i]==nums[i-1] && !used[i-1]){continue;}
            used[i]=true;
            temp.push_back(nums[i]);
            helper(nums,temp,used);
            temp.pop_back();used[i]=false;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        helper(nums,temp,used);
        return res;
    }
};