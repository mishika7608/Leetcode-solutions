class Solution {
public:
    void helper(vector<int>& nums, vector<int>& ans, vector<vector<int>>& res, vector<bool>& used){
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++){

            if(used[i]) continue;

            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;

            used[i]=true;
            ans.push_back(nums[i]);

            helper(nums,ans,res,used);

            ans.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        vector<int> ans;
        vector<bool> used(nums.size(),false);

        helper(nums,ans,res,used);

        return res;
    }
};