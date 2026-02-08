class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int n = nums.size();
        for (int i=0;i<n;i++){
            ans.push_back(nums[i]);
            while(ans.size()>=2 && ans[ans.size()-2]==ans[ans.size()-1]){
                long long v= ans[ans.size()-2];
                ans.pop_back();
                ans.back()+=v;
                // ans.back() %= 2e32;
            } 
        }
        return ans;
    }
};